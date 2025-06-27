/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "";
        string str="";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();

            if(curr==NULL){
                str+="#,";
            }
            else{
                str += to_string(curr->val) + ',';

                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return NULL;

        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            getline(s,str,',');
            if(str!="#"){
                TreeNode* leftN=new TreeNode(stoi(str));
                node->left=leftN;
                q.push(leftN);
            }
            getline(s,str,',');
            if(str!="#"){
                TreeNode* rightN=new TreeNode(stoi(str));
                node->right=rightN;
                q.push(rightN);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));