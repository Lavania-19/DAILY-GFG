class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int k, int x) {
        int n = arr.size();
        // Find the insertion point for x using lower_bound
        int right = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int left = right - 1;

        vector<int> result;

        while (k > 0) {
            // Skip x if it's present in the array
            if (right < n && arr[right] == x) right++;

            if (left < 0) {
                result.push_back(arr[right++]);
            } else if (right >= n) {
                result.push_back(arr[left--]);
            } else {
                int diffLeft = abs(arr[left] - x);
                int diffRight = abs(arr[right] - x);

                if (diffLeft < diffRight) {
                    result.push_back(arr[left--]);
                } else if (diffRight < diffLeft) {
                    result.push_back(arr[right++]);
                } else {
                    // If tie, choose the **larger value** per problem statement
                    if (arr[left] > arr[right]) {
                        result.push_back(arr[left--]);
                    } else {
                        result.push_back(arr[right++]);
                    }
                }
            }
            k--;
        }

        return result;
    }
};
