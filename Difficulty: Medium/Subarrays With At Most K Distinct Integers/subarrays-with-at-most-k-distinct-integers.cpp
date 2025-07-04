class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        int left = 0, right = 0;
        unordered_map<int, int> freq;
        int count = 0;

        for (right = 0; right < arr.size(); ++right) {
            // If it's a new distinct number
            if (freq[arr[right]] == 0) {
                k--;
            }
            freq[arr[right]]++;

            // Shrink the window if we have more than k distinct elements
            while (k < 0) {
                freq[arr[left]]--;
                if (freq[arr[left]] == 0) {
                    k++;
                }
                left++;
            }

            // Add the number of subarrays ending at right
            count += (right - left + 1);
        }
        return count;
    }
};
