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
    void inorder(TreeNode* root, int k, int& cnt, int& kth) {
        if (!root || cnt >= k) {
            return;
        }

        inorder(root->left, k, cnt, kth);
        cnt++;
        if (cnt == k) {
            kth = root->val;
            return;
        }
        inorder(root->right, k, cnt, kth);
    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        int kth = -1;
        inorder(root, k, cnt, kth);
        return kth;
    }
};