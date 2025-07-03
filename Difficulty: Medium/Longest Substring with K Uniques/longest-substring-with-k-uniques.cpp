#include <unordered_map>
#include <string>
using namespace std;

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        unordered_map<char, int> freq;
        int maxLen = -1;
        int left = 0;

        for (int right = 0; right < s.length(); ++right) {
            freq[s[right]]++;

            // Shrink window if unique characters exceed k
            while (freq.size() > k) {
                freq[s[left]]--;
                if (freq[s[left]] == 0) {
                    freq.erase(s[left]);
                }
                left++;
            }

            // Check if current window has exactly k distinct characters
            if (freq.size() == k) {
                maxLen = max(maxLen, right - left + 1);
            }
        }

        return maxLen;
    }
};
