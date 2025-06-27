/*

Definition for Binary Tree Node
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
    void helper(vector<vector<int>>& result,vector<int>& path,Node* root){
        if(root==NULL) return;
        
        path.push_back(root->data);
        
        if(!root->left && !root->right){
            result.push_back(path);
        }
        else{
            helper(result,path,root->left);
            
            helper(result,path,root->right);
        }
        
        path.pop_back();
    }
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>> result;
        vector<int> path;
        helper(result,path,root);
        return result;
    }
};