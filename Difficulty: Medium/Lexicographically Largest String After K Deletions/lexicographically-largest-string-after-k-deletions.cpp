class Solution {
  public:
    string maxSubseq(string& s, int k) {
        int to_remove = k;
        vector<char> result;

        for (char ch : s) {
            while (!result.empty() && to_remove > 0 && result.back() < ch) {
                result.pop_back();
                to_remove--;
            }
            result.push_back(ch);
        }

        // Final answer length should be s.size() - k
        int keep = s.size() - k;
        return string(result.begin(), result.begin() + keep);
    }
};
