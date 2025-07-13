class Solution {
  public:
    void getPaths(Node* root, vector<int>& path, vector<vector<int>>& result) {
        if (!root) return;

        path.push_back(root->data);

        // If it's a leaf node, add the path to result
        if (!root->left && !root->right) {
            result.push_back(path);
        } else {
            getPaths(root->left, path, result);
            getPaths(root->right, path, result);
        }

        // Backtrack
        path.pop_back();
    }

    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> result;
        vector<int> path;

        getPaths(root, path, result);
        return result;
    }
};
