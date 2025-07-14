/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParents( unordered_map<TreeNode*,TreeNode*>& parent,TreeNode* root){
        if(!root) return;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            if(node->left){
                q.push(node->left);
                parent[node->left]=node;
            }
            if(node->right){
                q.push(node->right);
                parent[node->right]=node;
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent;
        markParents(parent,root);
        queue<TreeNode*> q;
        q.push(target);
        int curr_level=0;
        unordered_map<TreeNode*,bool> vis;
        vis[target]=true;
        while(!q.empty()){
            int s=q.size(); 
            if(curr_level==k) break;
            curr_level++;
            for(int i=0;i<s;i++){
                auto node=q.front();
                q.pop();
                if(node->left && !vis[node->left]){
                    q.push(node->left);
                    vis[node->left]=true;
                }
                
                if(node->right && !vis[node->right]){
                    q.push(node->right);
                    vis[node->right]=true;
                }
                if(parent[node] && !vis[parent[node]]){
                    q.push(parent[node]);
                    vis[parent[node]]=true;
                }
            }
        
        }
        vector<int> temp;
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            temp.push_back(node->val);
        }
        return temp;
    }
};