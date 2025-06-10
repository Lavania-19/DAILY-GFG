class Solution {
  public:
    int countStrings(string &s) {
        int n = s.size();
        long long totalPairs = (1LL * n * (n - 1)) / 2;

        vector<int> freq(26, 0);
        for (char c : s)
            freq[c - 'a']++;

        long long sameCharPairs = 0;
        for (int f : freq) {
            sameCharPairs += (1LL * f * (f - 1)) / 2;
        }

        long long result = totalPairs - sameCharPairs;

        // Check: if any duplicate character exists, then we can include original string
        bool hasDuplicate = sameCharPairs > 0;

        return result + (hasDuplicate ? 1 : 0);
    }
};
