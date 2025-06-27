/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
     Node* markParents(unordered_map<Node*, Node*>& parent, Node* root, int target) {
        if (!root) return root;

        queue<Node*> q;
        q.push(root);
        Node* res = nullptr;

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            if (curr->data == target)
                res = curr;

            if (curr->left) {
                parent[curr->left] = curr;
                q.push(curr->left);
            }

            if (curr->right) {
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }

        return res;
    }
    int minTime(Node* root, int tar) {
        // code here
         unordered_map<Node*, Node*> parent;
        Node* target = markParents(parent, root, tar);

        unordered_map<Node*, bool> vis;
        queue<Node*> q;
        q.push(target);
        vis[target] = true;

        int maxi=0;
        while (!q.empty()) {
            int s = q.size();
           int flag=0;
            for (int i = 0; i < s; ++i) {
                Node* node = q.front();
                q.pop();

                if (node->left && !vis[node->left]) {
                    flag=1;
                    q.push(node->left);
                    vis[node->left] = true;
                }

                if (node->right && !vis[node->right]) {
                    flag=1;
                    q.push(node->right);
                    vis[node->right] = true;
                }

                if (parent[node] && !vis[parent[node]]) {
                    flag=1;
                    q.push(parent[node]);
                    vis[parent[node]] = true;
                }
            }
            if(flag)  maxi++;
        }
return maxi;
    }
};