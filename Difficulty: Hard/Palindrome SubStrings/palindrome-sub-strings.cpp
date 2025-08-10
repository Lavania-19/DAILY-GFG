#include <string>
using namespace std;

class Solution {
public:
    int countPS(const string &s) {
        int count = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            // even-length palindrome check
            checkPalin(s, i, i + 1, count);

            // odd-length palindrome check
            checkPalin(s, i, i, count);
        }
        return count;
    }

private:
    void checkPalin(const string &s, int i, int j, int &count) {
        while (i >= 0 && j < (int)s.length() && s[i] == s[j]) {
            if (j - i + 1 >= 2)
                count++;
            i--;
            j++;
        }
    }
};



