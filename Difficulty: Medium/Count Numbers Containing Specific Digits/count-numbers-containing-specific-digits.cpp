class Solution {
  public:
    int countValid(int n, vector<int>& arr) {
        vector<bool> banned(10, false);
        for (int d : arr) banned[d] = true;

        vector<int> allowed;
        vector<int> allowed_non_zero;

        for (int d = 0; d <= 9; d++) {
            if (!banned[d]) {
                allowed.push_back(d);
                if (d != 0) allowed_non_zero.push_back(d);
            }
        }

        // Total n-digit positive integers
        long long total = 9;
        for (int i = 1; i < n; i++) total *= 10;

        // If no allowed digits, then no invalid numbers
        if (allowed_non_zero.size() == 0) return total;

        long long invalid = allowed_non_zero.size();
        for (int i = 1; i < n; i++) invalid *= allowed.size();

        return total - invalid;
    }
};
