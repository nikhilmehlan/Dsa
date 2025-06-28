// Function to search a node in BST.
class Solution {

  public:
    int floor(Node* root, int input) {
        // Code here
         int floori=-1;
    while(root){
        if(root->data==input){
            floori=root->data;
            return floori;
        }
        else if(input>root->data){
            floori=root->data;
            root=root->right;
        }
        else{
            root=root->left;
        }
    }
    return floori;
    }
};