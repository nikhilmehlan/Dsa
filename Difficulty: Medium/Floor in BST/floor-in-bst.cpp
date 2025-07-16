// Function to search a node in BST.
class Solution {

  public:
    int floor(Node* root, int input) {
        // Code here
         int floor=-1;
    while(root){
        if(root->data==input){
            floor=root->data;
            return floor;
        }
        else if(root->data< input){
            floor=root->data;
            root=root->right;
        }
        else{
            root=root->left;
        }
    }
    return floor;
    }
};