// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>> adj(V);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            adj[u].push_back({v,wt});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,src});
        vector<int> dist(V,1e9);
        dist[src]=0;
        while(!pq.empty()){
            auto temp=pq.top();
            pq.pop();
            int node=temp.second;
            int wt=temp.first;
            for(auto it:adj[node]){
                int v=it.first;
                int d=it.second;
                if(wt+d<dist[v]){
                    dist[v]=wt+d;
                    pq.push({dist[v],v});
                }
            }
        }
        return dist;
    }
};