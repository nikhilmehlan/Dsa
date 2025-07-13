/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        // code here
        vector<int> result;
        if(!root) return result;
        map<int,int> mpp;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            auto node=temp.first;
            auto line=temp.second;
            if(mpp.find(line)==mpp.end()) mpp[line]=node->data;
            if(node->left){
                q.push({node->left,line-1});
            }
            if(node->right){
                q.push({node->right,line+1});
            }
        }
        for(auto it:mpp){
            result.push_back(it.second);
        }
        return result;
    }
};