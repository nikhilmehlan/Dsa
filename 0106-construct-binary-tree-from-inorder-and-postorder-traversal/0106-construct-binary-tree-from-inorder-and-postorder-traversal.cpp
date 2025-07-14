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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
         map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        TreeNode* root = build(postorder, 0, postorder.size() - 1, inorder, 0,
                               inorder.size() - 1, inMap);

        return root;
    }
   TreeNode* build(vector<int>& postorder, int ps, int pe, vector<int>& inorder,
                    int is, int ie, map<int, int>& inMap) {
        if (ps > pe || is > ie)
            return NULL;

        TreeNode* root = new TreeNode(postorder[pe]);
        int rootI = inMap[root->val];
        int numsleft = rootI - is;

        root->left = build(postorder, ps, ps + numsleft-1, inorder, is,
                           rootI - 1, inMap);

        root->right = build(postorder, ps + numsleft, pe-1, inorder, rootI + 1,
                            ie, inMap);
        return root;
    }
};