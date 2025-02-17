class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0; // Base case

        int leftHeight = findLeftHeight(root);
        int rightHeight = findRightHeight(root);

        // If the left and right heights are the same, it's a perfect binary tree
        if (leftHeight == rightHeight) 
            return (1 << leftHeight) - 1;

        // Otherwise, count recursively
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

private:
    int findLeftHeight(TreeNode* node) {
        int height = 0;
        while (node) {
            height++;
            node = node->left;
        }
        return height;
    }

    int findRightHeight(TreeNode* node) {
        int height = 0;
        while (node) {
            height++;
            node = node->right;
        }
        return height;
    }
};
