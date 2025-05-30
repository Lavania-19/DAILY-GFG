

class Solution {
    public int findMaxFork(Node root, int k) {
        int result = -1; // Initialize to -1 (assuming all node values >= 1)

        while (root != null) {
            if (root.data == k) {
                return k; // Exact match
            } else if (root.data < k) {
                result = root.data; // Possible answer
                root = root.right; // Try to find a closer value
            } else {
                root = root.left; // Skip current node, try smaller values
            }
        }

        return result;
    }
}

