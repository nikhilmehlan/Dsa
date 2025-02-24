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
    vector<int> ino;
    void inorder(TreeNode* node) {
        if (!node)
            return;
        inorder(node->left);
        ino.push_back(node->val);
        inorder(node->right);
    }
    bool isValidBST(TreeNode* root) {
        inorder(root);

        for (int i = 1; i < ino.size(); i++) {
            if (ino[i] <= ino[i - 1]) {
                return false;
            }
        }
        return true;
    }
};