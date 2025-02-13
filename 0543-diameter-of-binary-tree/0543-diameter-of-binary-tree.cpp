/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int diameter(TreeNode* root, int& maxi) {
        if (root == NULL)
            return 0;

        int lh = diameter(root->left, maxi);
        int rh = diameter(root->right, maxi);
        maxi = max(maxi, lh + rh);

        return max(lh, rh) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        diameter(root, maxi);
        return maxi;
    }
};