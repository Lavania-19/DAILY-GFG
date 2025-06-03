class Solution {
  public:
    int countSubstr(string& s, int k) {
        return countAtMostKDistinct(s, k) - countAtMostKDistinct(s, k - 1);
    }

  private:
    int countAtMostKDistinct(string& s, int k) {
        if (k == 0) return 0;

        int freq[26] = {0};
        int left = 0, right = 0, count = 0, distinct = 0;

        for (right = 0; right < s.size(); ++right) {
            int idx = s[right] - 'a';
            if (freq[idx] == 0)
                distinct++;
            freq[idx]++;

            while (distinct > k) {
                int lidx = s[left] - 'a';
                freq[lidx]--;
                if (freq[lidx] == 0)
                    distinct--;
                left++;
            }

            count += (right - left + 1);
        }

        return count;
    }
};
