import java.util.*;

class Solution {
    public int totalElements(int[] arr) {
        Map<Integer, Integer> map = new HashMap<>();
        int start = 0, maxLength = 0;

        for (int end = 0; end < arr.length; end++) {
            map.put(arr[end], map.getOrDefault(arr[end], 0) + 1);

            while (map.size() > 2) {
                map.put(arr[start], map.get(arr[start]) - 1);
                if (map.get(arr[start]) == 0) {
                    map.remove(arr[start]);
                }
                start++;
            }

            maxLength = Math.max(maxLength, end - start + 1);
        }

        return maxLength;
    }
}
