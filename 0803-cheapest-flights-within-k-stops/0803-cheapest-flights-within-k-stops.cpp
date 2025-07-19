class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
     vector<vector<pair<int, int>>> adj(n);
        for (auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        queue<pair<int,pair<int,int>>> q;
        vector<int> dist(n,1e9);
        q.push({0,{src,0}});
        while(!q.empty()){
            auto val=q.front();
            q.pop();
            int stops=val.first;
            int node=val.second.first;
            int wt=val.second.second;
            if(stops>k) continue;
            for(auto it:adj[node]){
                int v=it.first;
                int ew=it.second;
                if(wt+ew<dist[v] && stops<=k){
                    dist[v]=wt+ew;
                    q.push({stops+1,{v,dist[v]}});
                }
            }
        } 
        if(dist[dst]==1e9) return -1;
        return dist[dst];  
    }
};