class Solution {
    public int maxMinHeight(int[] arr, int k, int w) {
        int n = arr.length;
        int low = 0, high = (int)1e9 + k;  // Max height we could reach
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canAchieve(arr, k, w, mid)) {
                ans = mid;       // Try for higher
                low = mid + 1;
            } else {
                high = mid - 1;  // Try lower
            }
        }
        return ans;
    }

    private boolean canAchieve(int[] arr, int k, int w, int target) {
        int n = arr.length;
        int[] water = new int[n + 1];  // Difference array
        long ops = 0;
        long currWater = 0;

        for (int i = 0; i < n; i++) {
            currWater += water[i];
            int currentHeight = arr[i] + (int)currWater;
            if (currentHeight < target) {
                int needed = target - currentHeight;
                ops += needed;
                if (ops > k) return false;

                currWater += needed;
                if (i + w < water.length) {
                    water[i + w] -= needed;
                }
            }
        }
        return true;
    }
}
