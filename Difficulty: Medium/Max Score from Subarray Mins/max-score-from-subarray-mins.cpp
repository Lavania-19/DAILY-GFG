class Solution {
  public:
    int maxSum(vector<int> &arr) {
        int n = arr.size();
        int maxScore = 0;
        
        for (int i = 0; i < n - 1; ++i) {
            int a = arr[i];
            int b = arr[i + 1];
            int small = min(a, b);
            int secondSmall = max(a, b);  // in a pair, this is second smallest
            maxScore = max(maxScore, small + secondSmall);
        }

        return maxScore;
    }
};
