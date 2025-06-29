class Solution {
    public int splitArray(int[] arr, int k) {
        int low = 0, high = 0;
        for (int num : arr) {
            low = Math.max(low, num);
            high += num;
        }

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (isPossible(arr, k, mid)) {
                high = mid; // try smaller max sum
            } else {
                low = mid + 1; // need bigger max sum
            }
        }

        return low;
    }

    private boolean isPossible(int[] arr, int k, int maxSum) {
        int subarrays = 1, currSum = 0;
        for (int num : arr) {
            if (currSum + num > maxSum) {
                subarrays++;
                currSum = num;
                if (subarrays > k) return false;
            } else {
                currSum += num;
            }
        }
        return true;
    }
}
