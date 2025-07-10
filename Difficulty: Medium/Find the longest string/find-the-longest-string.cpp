class Solution {
  public:
    string longestString(vector<string> &words) {
        sort(words.begin(), words.end());
        unordered_set<string> s;
        string ans = "";

        for (string &word : words) {
            if (word.size() == 1 || s.count(word.substr(0, word.size() - 1))) {
                if (word.size() > ans.size()) {
                    ans = word;
                }
                s.insert(word);
            }
        }

        return ans;
    }
};
