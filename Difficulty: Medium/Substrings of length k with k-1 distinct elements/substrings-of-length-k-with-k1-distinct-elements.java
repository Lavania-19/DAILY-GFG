import java.util.*;

class Solution {
    public int substrCount(String s, int k) {
        if (s.length() < k) return 0;

        int count = 0;
        int[] freq = new int[26];  // only lowercase letters
        int distinct = 0;

        // Initialize the first window
        for (int i = 0; i < k; i++) {
            int idx = s.charAt(i) - 'a';
            if (freq[idx] == 0) distinct++;
            freq[idx]++;
        }
        if (distinct == k - 1) count++;

        // Slide the window
        for (int i = k; i < s.length(); i++) {
            // Remove leftmost character
            int leftIdx = s.charAt(i - k) - 'a';
            freq[leftIdx]--;
            if (freq[leftIdx] == 0) distinct--;

            // Add new character
            int rightIdx = s.charAt(i) - 'a';
            if (freq[rightIdx] == 0) distinct++;
            freq[rightIdx]++;

            if (distinct == k - 1) count++;
        }

        return count;
    }
}
