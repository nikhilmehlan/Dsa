class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // Nested map: column -> row -> multiset of values
        map<int, map<int, multiset<int>>> nodes;
        queue<tuple<TreeNode*, int, int>> q;  // node, column, row

        q.push({root, 0, 0});

        while (!q.empty()) {
            auto [node, col, row] = q.front();
            q.pop();

            nodes[col][row].insert(node->val);

            if (node->left)
                q.push({node->left, col - 1, row + 1});
            if (node->right)
                q.push({node->right, col + 1, row + 1});
        }

        vector<vector<int>> result;

        for (auto& [col, m] : nodes) {
            vector<int> colNodes;
            for (auto& [row, values] : m) {
                colNodes.insert(colNodes.end(), values.begin(), values.end());
            }
            result.push_back(colNodes);
        }

        return result;
    }
};
