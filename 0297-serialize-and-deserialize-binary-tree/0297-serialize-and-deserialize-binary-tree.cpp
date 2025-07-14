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
        if (root == NULL)
            return "";
        string str = "";
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            if (node == NULL)
                str += "#,";
            else {
                str += to_string(node->val) + ',';
                q.push(node->left);
                q.push(node->right);
            }
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty())
            return NULL;
        stringstream s(data);
        string str;
        getline(s, str, ',');

        TreeNode* node = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(node);
        while (!q.empty()) {
            auto top = q.front();
            q.pop();
            getline(s, str, ',');
            if (str != "#") {
                TreeNode* leftn = new TreeNode(stoi(str));
                top->left = leftn;
                q.push(leftn);
            }
            getline(s, str, ',');
            if (str != "#") {
                TreeNode* rightn = new TreeNode(stoi(str));
                top->right = rightn;
                q.push(rightn);
            }
        }
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));