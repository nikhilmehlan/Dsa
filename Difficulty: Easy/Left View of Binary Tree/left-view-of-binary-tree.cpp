/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution {
  public:
    vector<int> leftView(Node *root) {
        // code here
        vector<int> result;
    if (!root) return result;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        Node* node = nullptr;

        for (int i = 0; i < levelSize; ++i) {
            node = q.front(); q.pop();

            // Push children in the queue
            if (node->right) q.push(node->right);
            if (node->left) q.push(node->left);
        }

        // The last node at current level is the rightmost one
        if (node) result.push_back(node->data);
    }

    return result;
    }
};