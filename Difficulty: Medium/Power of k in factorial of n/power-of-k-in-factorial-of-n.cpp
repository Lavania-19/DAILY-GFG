class Solution {
  public:
    int maxKPower(int n, int k) {
        int ans = INT_MAX;

        // Step 1: Prime factorize k
        for (int i = 2; i * i <= k; ++i) {
            int count = 0;
            while (k % i == 0) {
                ++count;
                k /= i;
            }
            if (count > 0) {
                // Count how many times i divides n!
                int temp = 0;
                int N = n;
                while (N) {
                    temp += N / i;
                    N /= i;
                }
                ans = std::min(ans, temp / count);
            }
        }

        // If k is still greater than 1, it is prime
        if (k > 1) {
            int temp = 0;
            int N = n;
            while (N) {
                temp += N / k;
                N /= k;
            }
            ans = std::min(ans, temp);
        }

        return ans;
    }
};
