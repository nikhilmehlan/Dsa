class Solution {
  public:
    Node* successor(Node* root, int key){
        Node* ans = NULL;
        while(root){
            if(root->data > key){
                ans = root;
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return ans;
    }

    Node* predecessor(Node* root, int key){
        Node* ans = NULL;
        while(root){
            if(root->data < key){
                ans = root;
                root = root->right;
            } else {
                root = root->left;
            }
        }
        return ans;
    }

    vector<Node*> findPreSuc(Node* root, int key) {
        vector<Node*> ans;
        ans.push_back(predecessor(root, key));
        ans.push_back(successor(root, key));
        return ans;
    }
};
