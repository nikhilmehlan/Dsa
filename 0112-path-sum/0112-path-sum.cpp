class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false; // empty tree
        
        // If it's a leaf, check if remaining target equals node value
        if (!root->left && !root->right) {
            return targetSum == root->val;
        }
        
        // Recurse on children with reduced target
        return hasPathSum(root->left, targetSum - root->val) ||
               hasPathSum(root->right, targetSum - root->val);
    }
};
