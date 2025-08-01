class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int node, int col, vector<int>& color) {
        color[node] = col;
        for (auto it : graph[node]) {
            if (color[it] == -1) {
                if (!dfs(graph, it, !col, color)) {
                    return false;
                }
            } else if (color[it] == col) {
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (!dfs(graph, i, 0, color)) return false;
            }
        }

        return true;
    }
};
