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
    TreeNode* build(vector<int>& preorder, int ps, int pe, vector<int>& inorder,
                    int is, int ie, map<int, int> & imap) {
        if (ps > pe || is > ie) 
            return NULL;

            TreeNode* root = new TreeNode(preorder[ps]);

            int inRoot = imap[root->val];
            int numsleft = inRoot - is;

            root->left = build(preorder, ps + 1, ps + numsleft, inorder, is,
                               inRoot - 1, imap);
            root->right = build(preorder, ps + numsleft + 1, pe, inorder,
                                inRoot + 1, ie, imap);
            return root;
        }
    
        TreeNode* buildTree(vector<int> & preorder, vector<int> & inorder) {
            if (preorder.size() != inorder.size())
                return NULL;
            map<int, int> imap;
            for (int i = 0; i < inorder.size(); i++) {
                imap[inorder[i]] = i;
            }
            TreeNode* root = build(preorder, 0, preorder.size() - 1, inorder, 0,
                                   inorder.size() - 1, imap);

            return root;
        }
    };