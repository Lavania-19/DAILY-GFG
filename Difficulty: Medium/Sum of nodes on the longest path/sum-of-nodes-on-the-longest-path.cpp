/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    int maxSum = 0;
    int maxLen = 0;

    void dfs(Node* node, int sum, int len) {
        if (!node) return;

        sum += node->data;
        len++;

        // Leaf node
        if (!node->left && !node->right) {
            if (len > maxLen) {
                maxLen = len;
                maxSum = sum;
            } else if (len == maxLen) {
                maxSum = max(maxSum, sum);
            }
            return;
        }

        dfs(node->left, sum, len);
        dfs(node->right, sum, len);
    }

    int sumOfLongRootToLeafPath(Node *root) {
        dfs(root, 0, 0);
        return maxSum;
    }
};
