/* Tree node structure used in the program */
// struct Node {
//     int data;
//     Node *left;
//     Node *right;

//     Node(int val) {
//         data = val;
//         left = right = NULL;
//     }
// };

class NodeValue {
public:
    int maxNode, minNode, maxSize;

    NodeValue(int minNode, int maxNode, int maxSize) {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSize = maxSize;
    }
};

class Solution {
  public:
    // Helper function to find the largest BST subtree
    NodeValue helper(Node* root) {
        if (!root) return NodeValue(INT_MAX, INT_MIN, 0); // Note: swapped INT_MAX/INT_MIN to reflect min/max logic

        auto left = helper(root->left);
        auto right = helper(root->right);

        // Check if current subtree is a BST
        if (left.maxNode < root->data && root->data < right.minNode) {
            return NodeValue(
                min(left.minNode, root->data),
                max(right.maxNode, root->data),
                left.maxSize + right.maxSize + 1
            );
        }

        // Not a BST
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }

    int largestBst(Node *root) {
        return helper(root).maxSize;
    }
};
