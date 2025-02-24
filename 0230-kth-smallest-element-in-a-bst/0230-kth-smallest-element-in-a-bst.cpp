/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> result;
    int kthSmallest(TreeNode* root, int k) {
        helper(root);
        sort(result.begin(),result.end());
        return result[k-1];
    }
    void helper(TreeNode* root){
        if(root) result.push_back(root->val);
        else return;
        helper(root->left);
        helper(root->right);
    }
};