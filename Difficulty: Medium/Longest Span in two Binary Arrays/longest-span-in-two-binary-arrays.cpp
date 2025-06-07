class Solution {
  public:
    int longestCommonSum(vector<int> &a1, vector<int> &a2) {
        int n = a1.size();
        unordered_map<int, int> diffMap;
        int maxLen = 0, preSum1 = 0, preSum2 = 0;

        for (int i = 0; i < n; ++i) {
            preSum1 += a1[i];
            preSum2 += a2[i];

            int currDiff = preSum1 - preSum2;

            if (currDiff == 0) {
                maxLen = i + 1;
            }
            else if (diffMap.find(currDiff) != diffMap.end()) {
                maxLen = max(maxLen, i - diffMap[currDiff]);
            } else {
                diffMap[currDiff] = i;
            }
        }

        return maxLen;
    }
};
