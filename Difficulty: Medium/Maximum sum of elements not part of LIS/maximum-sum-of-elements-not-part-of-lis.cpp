class Solution {
  public:
    int nonLisMaxSum(vector<int>& arr) {
        int n = arr.size();
        vector<int> length(n, 1); // LIS length ending at i
        vector<int> sum(n); // Minimum sum of LIS ending at i

        for (int i = 0; i < n; ++i) {
            sum[i] = arr[i];
        }

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (arr[j] < arr[i]) {
                    if (length[j] + 1 > length[i]) {
                        length[i] = length[j] + 1;
                        sum[i] = sum[j] + arr[i];
                    } else if (length[j] + 1 == length[i]) {
                        sum[i] = min(sum[i], sum[j] + arr[i]);
                    }
                }
            }
        }

        // Find the LIS with maximum length and minimum sum
        int maxLen = 0, minLisSum = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (length[i] > maxLen) {
                maxLen = length[i];
                minLisSum = sum[i];
            } else if (length[i] == maxLen) {
                minLisSum = min(minLisSum, sum[i]);
            }
        }

        int totalSum = 0;
        for (int num : arr) {
            totalSum += num;
        }

        return totalSum - minLisSum;
    }
};

