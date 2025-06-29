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
    vector<int> temp;
    void inorder(TreeNode* node) {
        if (node == NULL)
            return;
        inorder(node->left);
        temp.push_back(node->val);
        inorder(node->right);
    }
    bool findTarget(TreeNode* root, int k) {
        inorder(root);
        int l = 0;
        int r = temp.size() - 1;
        while (l < r) {
            if (temp[l] + temp[r] == k)
                return true;
            else if (temp[l] + temp[r] < k)
                l++;
            else
                r--;
        }
        return false;
    }
};