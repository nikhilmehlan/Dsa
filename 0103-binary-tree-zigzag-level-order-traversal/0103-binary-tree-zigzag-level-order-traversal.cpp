/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL) return res;
        queue<TreeNode*> q;
        q.push(root);
        int lefttoright=1;
        while(!q.empty()){
            int s=q.size();
            vector<int> temp(s);
            int index=0;
            for(int i=0;i<s;i++){
                auto top=q.front();
                q.pop();
                if(lefttoright){
                    temp[index]=top->val;
                }else{
                    temp[s-index-1]=top->val;
                }
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
                index++;
            }
            res.push_back(temp);
            lefttoright=!lefttoright;
        }
        return res;
    }
};