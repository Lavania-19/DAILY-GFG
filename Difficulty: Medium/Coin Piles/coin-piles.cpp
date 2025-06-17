class Solution {
  public:
    int minimumCoins(vector<int>& arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        // Compute prefix sum
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + arr[i];
        }

        // Compute suffix sum
        vector<long long> suffix(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            suffix[i] = suffix[i + 1] + arr[i];
        }

        long long min_remove = LLONG_MAX;

        for (int i = 0; i < n; ++i) {
            int low = arr[i];
            int high = low + k;

            // Remove coins from elements < low
            long long remove_lower = prefix[i];

            // Find first index j where arr[j] > high
            int j = upper_bound(arr.begin(), arr.end(), high) - arr.begin();
            long long remove_upper = 0;

            if (j < n) {
                // Total coins above high: suffix[j]
                // But we want to keep (high) in each of those, so:
                int count = n - j;
                remove_upper = suffix[j] - 1LL * count * high;
            }

            min_remove = min(min_remove, remove_lower + remove_upper);
        }

        return (int)min_remove;
    }
};
