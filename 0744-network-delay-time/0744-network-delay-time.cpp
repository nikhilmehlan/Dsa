class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int> dist(n+1,1e9);
        dist[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int dis=it.first;
            int node=it.second;

            for(auto itr:adj[node]){
                int adjnode=itr.first;
                int wt=itr.second;
                if(wt+dis<dist[adjnode]){
                    dist[adjnode]=wt+dis;
                    pq.push({dist[adjnode],adjnode});
                }
            }
        }
        int ans=-1;
        for(int i=1;i<n+1;i++){
            if(dist[i]==1e9) return -1;
            ans=max(ans,dist[i]);
        }
        return ans;
    }
};