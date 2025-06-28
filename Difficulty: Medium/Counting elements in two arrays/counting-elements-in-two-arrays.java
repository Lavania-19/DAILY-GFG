import java.util.*;

class Solution {
    public static ArrayList<Integer> countLessEq(int a[], int b[]) {
        Arrays.sort(b); // Step 1: sort array b
        ArrayList<Integer> result = new ArrayList<>();

        for (int num : a) {
            // Step 2: use binary search to find count of elements ≤ num in b[]
            int count = upperBound(b, num);
            result.add(count);
        }
        return result;
    }

    // Returns the index of the first element greater than x
    // Hence, count of elements ≤ x is equal to this index
    private static int upperBound(int[] arr, int x) {
        int low = 0, high = arr.length;
        while (low < high) {
            int mid = (low + high) / 2;
            if (arr[mid] <= x) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low; // All elements at index < low are ≤ x
    }
}
