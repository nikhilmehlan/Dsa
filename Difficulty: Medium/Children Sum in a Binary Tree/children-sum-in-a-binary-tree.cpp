/*Complete the function below

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){80
        data = x;
        left = right = NULL;
    }
};
*/

class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    bool helper(Node* root){
        if(root==NULL){
            return true;
        }
        
        if(root->left==NULL && root->right==NULL) return true;
        
        int lsum=0,rsum=0;
        if(root->left) lsum+=root->left->data;
        if(root->right) rsum+=root->right->data;
        
        bool valid=(root->data==(lsum+rsum));
        
        bool isleft=helper(root->left);
        bool isright=helper(root->right);
        
        return valid && isleft && isright;
    }
    int isSumProperty(Node *root)
    {
     // Add your code here
     if(helper(root)) return 1;
     else return 0;
    }
};
