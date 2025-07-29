class Solution {
    public:
    vector<int> asciirange(string& s) {
        vector<int> first(26, -1), second(26, -1);
        int n = s.size();
        vector<int> prefix(n, 0);
        //base conditions
        if (n == 1)  return { s[0] - '0' };
        prefix[0] = s[0] - 0;
        for (int i = 0;i < n;i++)
        {
            if (i != 0)
                prefix[i] = (prefix[i] + s[i] - 0) + prefix[i - 1];
            if (first[s[i] - 'a'] == -1)
                first[s[i] - 'a'] = i;
            else
                second[s[i] - 'a'] = i;
        
        }
        
        vector<int> ans;
        for (int i = 0;i < 26;i++)
        {
            if (second[i] > 0 && first[i] != -1)
            {
                int b = second[i];
                int a = first[i];
                int fa = prefix[b - 1] - prefix[a];
                if(fa > 0)
                    ans.push_back(fa);
        
            }
        }
    
    return ans;
    }
};

