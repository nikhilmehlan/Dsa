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
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;
    TreeNode* prev;
    void helper(TreeNode* root){
        if(!root) return;
        helper(root->left);
        if(prev!=NULL && root->val<prev->val){
            if(!first){
                first=prev;
                middle=root;
            }
            else{
                last=root;
            }
        }
        prev=root;
        helper(root->right);
    }
    void recoverTree(TreeNode* root) {
        // if(!root) return;
        first=middle=last=NULL;
        prev=new TreeNode(INT_MIN);
        helper(root);
        if(first && last) swap(first->val,last->val);
        else if(first && middle) swap(first->val,middle->val);
    }
};