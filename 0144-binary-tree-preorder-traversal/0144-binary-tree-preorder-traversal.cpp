class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        TreeNode* curr = root;

        while (curr != NULL) {
            if (curr->left == NULL) {
                preorder.push_back(curr->val);  // Visit when no left child
                curr = curr->right;
            } else {
                TreeNode* prev = curr->left;
                while (prev->right && prev->right != curr) {
                    prev = prev->right;
                }

                if (prev->right == NULL) {
                    preorder.push_back(curr->val);  // ✅ Visit BEFORE threading
                    prev->right = curr;
                    curr = curr->left;
                } else {
                    prev->right = NULL;
                    curr = curr->right;
                }
            }
        }

        return preorder;
    }
};
