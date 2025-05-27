class Solution {
  public:
    int idx;

    void findLeaves(vector<int>& preorder, int minVal, int maxVal, vector<int>& leaves) {
        if (idx >= preorder.size() || preorder[idx] < minVal || preorder[idx] > maxVal) return;

        int rootVal = preorder[idx++];
        
        int tempIdx = idx;
        findLeaves(preorder, minVal, rootVal - 1, leaves); // left subtree
        findLeaves(preorder, rootVal + 1, maxVal, leaves); // right subtree

        // If both subtrees didn't advance idx, it's a leaf node
        if (tempIdx == idx) {
            leaves.push_back(rootVal);
        }
    }

    vector<int> leafNodes(vector<int>& preorder) {
        idx = 0;
        vector<int> leaves;
        findLeaves(preorder, INT_MIN, INT_MAX, leaves);
        return leaves;
    }
};

