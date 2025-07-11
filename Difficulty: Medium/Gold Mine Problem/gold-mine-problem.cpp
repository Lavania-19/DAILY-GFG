class Solution {
  public:
    int maxGold(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        // Process last column first
        for (int i = 0; i < n; i++) {
            dp[i][m-1] = mat[i][m-1];
        }
        
        // Fill the table from right to left
        for (int j = m-2; j >= 0; j--) {
            for (int i = 0; i < n; i++) {
                int right = dp[i][j+1];
                int right_up = (i == 0) ? 0 : dp[i-1][j+1];
                int right_down = (i == n-1) ? 0 : dp[i+1][j+1];
                
                dp[i][j] = mat[i][j] + max({right, right_up, right_down});
            }
        }
        
        // Find the maximum value in first column
        int max_gold = 0;
        for (int i = 0; i < n; i++) {
            max_gold = max(max_gold, dp[i][0]);
        }
        
        return max_gold;
    }
};
