class Solution {
  public:
    vector<int> search(string &pat, string &txt) {
        int m = pat.size(), n = txt.size();
        const int base = 26;
        const int mod = 1e9 + 7;
        
        if (m > n) return {}; // pattern longer than text

        long long patHash = 0, txtHash = 0, power = 1;
        
        // Precompute highest power for rolling hash
        for (int i = 0; i < m - 1; ++i) {
            power = (power * base) % mod;
        }

        // Compute hash of pattern and first window of text
        for (int i = 0; i < m; ++i) {
            patHash = (patHash * base + (pat[i] - 'a')) % mod;
            txtHash = (txtHash * base + (txt[i] - 'a')) % mod;
        }

        vector<int> result;
        for (int i = 0; i <= n - m; ++i) {
            if (patHash == txtHash) {
                // Potential match, confirm by actual substring comparison
                if (txt.substr(i, m) == pat) {
                    result.push_back(i + 1);  // 1-based index
                }
            }

            // Roll the hash: remove leftmost and add next character
            if (i < n - m) {
                txtHash = (txtHash - (txt[i] - 'a') * power % mod + mod) % mod;
                txtHash = (txtHash * base + (txt[i + m] - 'a')) % mod;
            }
        }
        return result;
    }
};
