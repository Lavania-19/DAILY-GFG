class Solution {
  public:
    // Helper function to add two numeric strings
    string addStrings(string a, string b) {
        string res;
        int carry = 0, i = a.size()-1, j = b.size()-1;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            carry = sum / 10;
            res += (sum % 10 + '0');
        }

        reverse(res.begin(), res.end());
        return res;
    }

    // Recursive check
    bool check(string s, int start, string a, string b) {
        string sum = addStrings(a, b);
        int len = sum.size();

        if (start + len > s.size() || s.substr(start, len) != sum)
            return false;

        if (start + len == s.size())
            return true;

        return check(s, start + len, b, sum);
    }

    bool isSumString(string &s) {
        int n = s.size();
        for (int i = 1; i < n; i++) {
            for (int j = 1; i + j < n; j++) {
                string a = s.substr(0, i);
                string b = s.substr(i, j);
                
                if ((a.size() > 1 && a[0] == '0') || (b.size() > 1 && b[0] == '0'))
                    continue;

                if (check(s, i + j, a, b))
                    return true;
            }
        }
        return false;
    }
};
