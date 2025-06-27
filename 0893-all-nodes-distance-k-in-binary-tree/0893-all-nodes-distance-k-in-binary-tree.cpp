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
    void markParents(unordered_map<TreeNode*,TreeNode*>& parent,TreeNode* root){
        if(!root) return;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(curr->left){
                parent[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right){
                parent[curr->right]=curr;
                q.push(curr->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent;
        markParents(parent,root);
        unordered_map<TreeNode*,bool> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis[target]=true;
        int curr_level=0;
        while(!q.empty()){
            int s=q.size();
            if(curr_level==k) break;
            curr_level++;
            for(int i=0;i<s;i++){
                TreeNode* node=q.front();
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
        } vector<int> ans;

        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            ans.push_back(curr->val);
        }
        return ans;
    }
};