// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Adjacency list
        vector<vector<pair<int,int>>> adj(V);
        for(auto &it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v, wt});  // Directed graph
            // If undirected, also add: adj[v].push_back({u, wt});
        }

        vector<int> dist(V, 1e9);
        dist[src] = 0;

        set<pair<int,int>> st; // (distance, node)
        st.insert({0, src});

        while(!st.empty()) {
            auto top = *(st.begin());
            st.erase(st.begin());
            int node = top.second;
            int nodeDist = top.first;

            for(auto &neighbor : adj[node]) {
                int v = neighbor.first;
                int wt = neighbor.second;

                if(dist[node] + wt < dist[v]) {
                    // If v already in set, erase the old entry
                    if(dist[v] != 1e9) {
                        st.erase({dist[v], v});
                    }
                    dist[v] = dist[node] + wt;
                    st.insert({dist[v], v});
                }
            }
        }

        return dist;
    }
};
