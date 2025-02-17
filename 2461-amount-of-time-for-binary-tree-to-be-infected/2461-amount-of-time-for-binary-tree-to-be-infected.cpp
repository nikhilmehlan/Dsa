/**
 * Definition for a binary tree  TreeNode.
 * struct Tree TreeNode {
 *     int val;
 *     Tree TreeNode *left;
 *     Tree TreeNode *right;
 *     Tree TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     Tree TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     Tree TreeNode(int x, Tree TreeNode *left, Tree TreeNode *right) : val(x),
 * left(left), right(right) {}
 * };
 */
class Solution {
public:
    int helper(TreeNode* target, map<TreeNode*, TreeNode*>& mpp) {
        queue<TreeNode*> q;
        q.push(target);
        map<TreeNode*, int> vis;
        vis[target] = 1;
        int burn = 0;
        while (!q.empty()) {
            int size = q.size();
            int fl = 0;
            for (int i = 0; i < size; i++) {
                auto TreeNode = q.front();
                q.pop();
                if (TreeNode->left && !vis[TreeNode->left]) {
                    fl = 1;
                    vis[TreeNode->left] = 1;
                    q.push(TreeNode->left);
                }
                if (TreeNode->right && !vis[TreeNode->right]) {
                    fl = 1;
                    vis[TreeNode->right] = 1;
                    q.push(TreeNode->right);
                }
                if (mpp[TreeNode] && !vis[mpp[TreeNode]]) {
                    fl = 1;
                    vis[mpp[TreeNode]] = 1;
                    q.push(mpp[TreeNode]);
                }
            }
            if (fl)
                burn++;
        }
        return burn;
    }
    TreeNode* parent(TreeNode* root, int target,
                     map<TreeNode*, TreeNode*>& mpp) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* res;
        while (!q.empty()) {
            TreeNode* TreeNode = q.front();
            if (TreeNode->val == target)
                res = TreeNode;
            q.pop();
            if (TreeNode->left) {
                mpp[TreeNode->left] = TreeNode;
                q.push(TreeNode->left);
            }
            if (TreeNode->right) {
                mpp[TreeNode->right] = TreeNode;
                q.push(TreeNode->right);
            }
        }
        return res;
    }
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*, TreeNode*> mpp;
        TreeNode* target = parent(root, start, mpp);
        int burn = helper(target, mpp);
        return burn;
    }
};