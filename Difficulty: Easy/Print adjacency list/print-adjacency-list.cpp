class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
        // Code here
        vector<vector<int>> graph(V);
        for(int i=0;i<edges.size();i++){
            int u=edges[i].first;
            int v=edges[i].second;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        return graph;
    }
};