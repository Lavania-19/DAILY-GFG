#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minValue(string &s, int k) {
        // Step 1: Count frequency of each character
        vector<int> freq(26, 0);
        for (char ch : s) {
            freq[ch - 'a']++;
        }
        
        // Step 2: Max-heap to store frequencies
        priority_queue<int> pq;
        for (int f : freq) {
            if (f > 0) {
                pq.push(f);
            }
        }

        // Step 3: Remove k characters
        while (k-- > 0 && !pq.empty()) {
            int top = pq.top(); pq.pop();
            if (top > 1) {
                pq.push(top - 1);
            }
        }

        // Step 4: Calculate the sum of squares
        int result = 0;
        while (!pq.empty()) {
            int f = pq.top(); pq.pop();
            result += f * f;
        }

        return result;
    }
};
