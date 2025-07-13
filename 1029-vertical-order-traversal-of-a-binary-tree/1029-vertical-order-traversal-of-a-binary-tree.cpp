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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> nodes;
        queue<tuple<TreeNode*,int,int>> q;
        q.push({root,0,0});
        vector<vector<int>> result;
        while(!q.empty()){
            auto [node,col,row] =q.front();
            q.pop();
            nodes[col][row].insert(node->val);
            if(node->left){
                q.push({node->left,col-1,row+1});
            }

            if(node->right){
                q.push({node->right,col+1,row+1});
            }
        }
        for(auto& col:nodes){
            vector<int> colEnds;
            for(auto& row:col.second){
                colEnds.insert(colEnds.end(),row.second.begin(),row.second.end());
            }
            result.push_back(colEnds);
        }
        return result;
    }
};