class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;  // base case: empty tree
        
        // If one child is null, we must take the depth from the other child
        if (!root->left) return 1 + minDepth(root->right);
        if (!root->right) return 1 + minDepth(root->left);
        
        // Both children exist → take the smaller depth
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};
