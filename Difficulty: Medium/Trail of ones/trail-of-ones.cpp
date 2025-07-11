class Solution {
  public:
    int countConsec(int n) {
        // Total number of binary strings of length n
        int total = 1 << n;  // same as 2^n

        // dp[i] = number of strings of length i with NO consecutive 1's
        int dp[n + 2];
        dp[1] = 2; // "0", "1"
        dp[2] = 3; // "00", "01", "10"

        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return total - dp[n];
    }
};
