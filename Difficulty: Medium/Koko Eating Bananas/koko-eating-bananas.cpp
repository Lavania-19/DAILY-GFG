class Solution {
  public:
    // Helper function to check if Koko can eat all bananas with speed s in k hours
    bool canEatAll(vector<int>& arr, int k, int s) {
        int hours = 0;
        for (int bananas : arr) {
            hours += (bananas + s - 1) / s;  // Ceil(bananas / s)
        }
        return hours <= k;
    }

    int kokoEat(vector<int>& arr, int k) {
        int low = 1, high = *max_element(arr.begin(), arr.end());
        int result = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canEatAll(arr, k, mid)) {
                result = mid;
                high = mid - 1;  // Try smaller s
            } else {
                low = mid + 1;   // Increase s
            }
        }
        return result;
    }
};
