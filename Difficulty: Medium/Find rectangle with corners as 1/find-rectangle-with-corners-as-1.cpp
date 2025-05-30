class Solution {
  public:
    bool ValidCorner(vector<vector<int>>& mat) {
        int rows = mat.size();
        if (rows == 0) return false;
        int cols = mat[0].size();

        // Check all pairs of rows
        for (int i = 0; i < rows; ++i) {
            for (int j = i + 1; j < rows; ++j) {
                // Track columns where both mat[i][k] and mat[j][k] are 1
                unordered_set<int> onesCols;
                for (int k = 0; k < cols; ++k) {
                    if (mat[i][k] == 1 && mat[j][k] == 1) {
                        if (!onesCols.empty()) {
                            // Already found one pair, so this is at least 2 columns → rectangle found
                            return true;
                        }
                        onesCols.insert(k);
                    }
                }
            }
        }

        return false;
    }
};
