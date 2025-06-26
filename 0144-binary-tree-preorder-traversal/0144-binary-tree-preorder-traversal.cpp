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
    void builder(TreeNode* root,vector<int>& result){
        if(root==NULL){
            return;
        }
        result.push_back(root->val);

        builder(root->left,result);
        builder(root->right,result);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        builder(root,result);
        return result;
    }
};