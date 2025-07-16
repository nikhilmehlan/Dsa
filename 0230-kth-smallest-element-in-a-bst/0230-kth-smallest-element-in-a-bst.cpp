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
    void helper(TreeNode* root,int k,int& kth,int& cnt){
        if(!root || cnt>=k) return;
        helper(root->left,k,kth,cnt);
        cnt++;
        if(cnt==k){
            kth=root->val;
            return;
        }
        helper(root->right,k,kth,cnt);
    }
    int kthSmallest(TreeNode* root, int k) {
        int kth=0;
        int cnt=0;
        helper(root,k,kth,cnt);
        return kth;
    }
};