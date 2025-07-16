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
    int ind = 0;
    TreeNode* helper(vector<int>& preorder, int minv, int maxv) {
        if (ind >= preorder.size()) {
            return NULL;
        }
        int val = preorder[ind];
        if (val < minv || val > maxv) {
            return NULL;
        }
        TreeNode* root=new TreeNode(val);
        ind++;
        root->left=helper(preorder,minv,val-1);
        root->right=helper(preorder,val+1,maxv);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return helper(preorder, INT_MIN, INT_MAX);
    }
};