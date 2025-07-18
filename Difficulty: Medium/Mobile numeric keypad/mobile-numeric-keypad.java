class Solution {
    public int getCount(int n) {
        if (n == 1) return 10;

        int[][] dp = new int[10][n + 1];
        
        // Define the adjacency list (including self-move)
        int[][] neighbors = {
            {0, 8},     // 0
            {1, 2, 4},  // 1
            {2, 1, 3, 5}, // 2
            {3, 2, 6},  // 3
            {4, 1, 5, 7}, // 4
            {5, 2, 4, 6, 8}, // 5
            {6, 3, 5, 9}, // 6
            {7, 4, 8},  // 7
            {8, 5, 7, 9, 0}, // 8
            {9, 6, 8}   // 9
        };

        // Initialize for length 1
        for (int i = 0; i <= 9; i++) {
            dp[i][1] = 1;
        }

        // Build up for lengths 2 to n
        for (int len = 2; len <= n; len++) {
            for (int digit = 0; digit <= 9; digit++) {
                dp[digit][len] = 0;
                for (int neighbor : neighbors[digit]) {
                    dp[digit][len] += dp[neighbor][len - 1];
                }
            }
        }

        // Total combinations of length n starting from any digit
        int total = 0;
        for (int i = 0; i <= 9; i++) {
            total += dp[i][n];
        }

        return total;
    }
}
