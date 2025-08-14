class Solution {
  public:
    Node* LCA(Node* root, int a, int b) {
        if (!root) return NULL;
        if (root->data == a || root->data == b) return root;
        
        Node* left = LCA(root->left, a, b);
        Node* right = LCA(root->right, a, b);
        
        if (!left) return right;
        if (!right) return left;
        return root;
    }
    
    int dist(Node* root, int target) {
        if (!root) return -1;
        if (root->data == target) return 0;
        
        int left = dist(root->left, target);
        if (left != -1) return left + 1;
        
        int right = dist(root->right, target);
        if (right != -1) return right + 1;
        
        return -1;
    }
    
    int findDist(Node* root, int a, int b) {
        Node* lca = LCA(root, a, b);
        int da = dist(lca, a);
        int db = dist(lca, b);
        return da + db;
    }
};
