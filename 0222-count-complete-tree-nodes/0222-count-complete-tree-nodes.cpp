class Solution {
public:
    void helper(int &cnt, TreeNode* root) {  // Pass cnt by reference
        if (root == nullptr) return;  // Base case

        cnt++;  // Count the current node
        helper(cnt, root->left);  // Recur for left subtree
        helper(cnt, root->right); // Recur for right subtree
    }

    int countNodes(TreeNode* root) {
        int cnt = 0;
        helper(cnt, root);
        return cnt;
    }
};
