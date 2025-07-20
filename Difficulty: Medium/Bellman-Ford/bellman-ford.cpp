class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        const int INF = 1e8;
        vector<int> dist(V, INF);
        dist[src] = 0;

        // Relax all edges V-1 times
        for (int i = 0; i < V - 1; i++) {
            for (auto it : edges) {
                int u = it[0], v = it[1], wt = it[2];
                if (dist[u] != INF && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }

        // Check for negative weight cycle
        for (auto it : edges) {
            int u = it[0], v = it[1], wt = it[2];
            if (dist[u] != INF && dist[u] + wt < dist[v]) {
                return {-1};  // Negative cycle detected
            }
        }

        return dist;
    }
};
