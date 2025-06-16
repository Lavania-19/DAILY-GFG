class Solution {
  public:
    long long getCost(const vector<int>& heights, const vector<int>& cost, int target) {
        long long totalCost = 0;
        for (int i = 0; i < heights.size(); ++i) {
            totalCost += 1LL * abs(heights[i] - target) * cost[i];
        }
        return totalCost;
    }

    int minCost(vector<int>& heights, vector<int>& cost) {
        int low = *min_element(heights.begin(), heights.end());
        int high = *max_element(heights.begin(), heights.end());
        
        // Ternary Search to minimize cost function
        while (high - low > 2) {
            int mid1 = low + (high - low) / 3;
            int mid2 = high - (high - low) / 3;
            long long cost1 = getCost(heights, cost, mid1);
            long long cost2 = getCost(heights, cost, mid2);
            if (cost1 < cost2)
                high = mid2;
            else
                low = mid1;
        }

        long long ans = LLONG_MAX;
        for (int i = low; i <= high; ++i) {
            ans = min(ans, getCost(heights, cost, i));
        }
        return ans;
    }
};
