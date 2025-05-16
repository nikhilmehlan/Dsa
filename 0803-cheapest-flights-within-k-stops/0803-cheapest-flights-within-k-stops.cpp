class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
     
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,pair<int,int>>> q;
        vector<int> dist(n,1e9);
        dist[src]=0;
        q.push({0,{src,0}});
        // {stops,{node,dis}};
        
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int stops=it.first;
            int node=it.second.first;
            int dis=it.second.second;
            if(stops>k) continue;
            for(auto itr:adj[node]){
                int adjnode=itr.first;
                int edw=itr.second;

                if(dis+edw<dist[adjnode] && stops<=k){
                    dist[adjnode]=dis+edw;
                    q.push({stops+1,{adjnode,dist[adjnode]}});
                }
            }
        }
        if(dist[dst]==1e9) return -1;
        return dist[dst];
    }
};