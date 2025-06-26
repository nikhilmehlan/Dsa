/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    bool isLeaf(Node* root){
        return !root->left && !root->right;
    }
    void addleft(Node *root,vector<int>& res){
        Node* curr=root->left;
        while(curr){
            if(!isLeaf(curr)) res.push_back(curr->data);
            if(curr->left) curr=curr->left;
            else curr=curr->right;
        }
    }
    void addright(Node *root,vector<int>& res){
        Node* curr=root->right;
        vector<int> temp;
        while(curr){
            if(!isLeaf(curr)) temp.push_back(curr->data);
            if(curr->right) curr=curr->right;
            else curr=curr->left;
        }
        for(int i=temp.size()-1;i>=0;i--){
            res.push_back(temp[i]);
        }
    }
    void addleaf(Node* root,vector<int>& res){
        if(isLeaf(root)){
            res.push_back(root->data);
            return;
        }
        if(root->left) addleaf(root->left,res);
        if(root->right) addleaf(root->right,res);
    }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> res;
        if(root==NULL) return res;
        if(!isLeaf(root)) res.push_back(root->data);
        addleft(root,res);
        addleaf(root,res);
        addright(root,res);
        return res;
        
    }
};