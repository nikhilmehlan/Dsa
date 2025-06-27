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

    vector<int> KDistanceNodes(Node* root, int tar, int k) {
        unordered_map<Node*, Node*> parent;
        Node* target = markParents(parent, root, tar);

        unordered_map<Node*, bool> vis;
        queue<Node*> q;
        q.push(target);
        vis[target] = true;

        int curr_level = 0;

        while (!q.empty()) {
            int s = q.size();
            if (curr_level == k) break;
            curr_level++;

            for (int i = 0; i < s; ++i) {
                Node* node = q.front();
                q.pop();

                if (node->left && !vis[node->left]) {
                    q.push(node->left);
                    vis[node->left] = true;
                }

                if (node->right && !vis[node->right]) {
                    q.push(node->right);
                    vis[node->right] = true;
                }

                if (parent[node] && !vis[parent[node]]) {
                    q.push(parent[node]);
                    vis[parent[node]] = true;
                }
            }
        }

        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front()->data);
            q.pop();
        }

        sort(ans.begin(), ans.end()); // ✅ Sort the result as required
        return ans;
    }
};
