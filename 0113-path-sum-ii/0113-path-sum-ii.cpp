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
    void dfs(TreeNode* root, int target,vector<int>& path,vector<vector<int>>& ans){
        if(!root) return;

        path.push_back(root->val);

        if(!root->left && !root->right && root->val==target){
            ans.push_back(path);
        }
        else{
            if(root->left) dfs(root->left,target-root->val,path,ans);
            if(root->right) dfs(root->right,target-root->val,path,ans);
        }
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(root,targetSum,path,ans);
        return ans;
    }
};