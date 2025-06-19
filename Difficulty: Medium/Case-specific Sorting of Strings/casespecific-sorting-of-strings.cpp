class Solution {
  public:
    string caseSort(string& s) {
        string lower, upper;

        // Separate characters by case
        for (char c : s) {
            if (islower(c))
                lower.push_back(c);
            else
                upper.push_back(c);
        }

        // Sort both separately
        sort(lower.begin(), lower.end());
        sort(upper.begin(), upper.end());

        // Merge back keeping original case positions
        int l = 0, u = 0;
        string result = "";

        for (char c : s) {
            if (islower(c)) {
                result.push_back(lower[l++]);
            } else {
                result.push_back(upper[u++]);
            }
        }

        return result;
    }
};
