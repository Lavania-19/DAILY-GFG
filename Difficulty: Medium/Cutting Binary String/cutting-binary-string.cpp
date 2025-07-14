class Solution {
  public:
    int cuts(string s) {
        int n = s.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        unordered_set<long long> powersOf5;
        long long p = 1;
        while (p <= (1LL << 30)) {
            powersOf5.insert(p);
            p *= 5;
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (s[j] == '0') continue; // No leading zeros
                string sub = s.substr(j, i - j);
                long long num = stoll(sub, nullptr, 2);
                if (powersOf5.count(num)) {
                    if (dp[j] != INT_MAX)
                        dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[n] == INT_MAX ? -1 : dp[n];
    }
};
