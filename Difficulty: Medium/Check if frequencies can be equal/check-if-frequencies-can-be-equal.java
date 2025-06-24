class Solution {
    boolean sameFreq(String s) {
        Map<Character, Integer> freq = new HashMap<>();
        for (char c : s.toCharArray()) {
            freq.put(c, freq.getOrDefault(c, 0) + 1);
        }

        // Count how many times each frequency occurs
        Map<Integer, Integer> freqCount = new HashMap<>();
        for (int f : freq.values()) {
            freqCount.put(f, freqCount.getOrDefault(f, 0) + 1);
        }

        // Case 1: All characters already have same frequency
        if (freqCount.size() == 1) return true;

        // Case 2: Two different frequencies
        if (freqCount.size() == 2) {
            int f1 = 0, c1 = 0, f2 = 0, c2 = 0;
            Iterator<Map.Entry<Integer, Integer>> it = freqCount.entrySet().iterator();
            
            Map.Entry<Integer, Integer> entry1 = it.next();
            f1 = entry1.getKey();
            c1 = entry1.getValue();

            Map.Entry<Integer, Integer> entry2 = it.next();
            f2 = entry2.getKey();
            c2 = entry2.getValue();

            // Try both orders
            if ((c1 == 1 && (f1 - 1 == f2 || f1 == 1)) || 
                (c2 == 1 && (f2 - 1 == f1 || f2 == 1))) {
                return true;
            }
        }

        return false;
    }
}
