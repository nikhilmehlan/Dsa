class Solution {
  public:
    void dfsIterative(vector<vector<int>>& graph, vector<bool>& visited, int start, vector<int>& component) {
        stack<int> stk;
        stk.push(start);
        visited[start] = true;

        while (!stk.empty()) {
            int node = stk.top();
            stk.pop();
            component.push_back(node);

            for (int neighbour : graph[node]) {
                if (!visited[neighbour]) {
                    visited[neighbour] = true;
                    stk.push(neighbour);
                }
            }
        }
    }

    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        vector<vector<int>> graph(V);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<vector<int>> components;
        vector<bool> visited(V, false);

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                vector<int> component;
                dfsIterative(graph, visited, i, component);
                components.push_back(component);
            }
        }

        return components;
    }
};
