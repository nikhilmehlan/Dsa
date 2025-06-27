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
    // from left to right in Binary .
    vector<int> topView(Node *root) {
        // code here
         vector<int> result;
        if(!root) return result;
        map<int,int> mpp;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            auto top=q.front();
            q.pop();
            Node* node=top.first;
            int level=top.second;
            if(mpp.find(level)==mpp.end()) mpp[level]=node->data;

            if(node->left){
                q.push({node->left,level-1});
            }
            if(node->right){
                q.push({node->right,level+1});
            }

        }
        for(auto it:mpp){
            result.push_back(it.second);
        }
        return result;
    }
};