//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(n+1,1e9),parent(n+1);
        for(int i=1;i<n+1;i++){
            parent[i]=i;
        }
        pq.push({0,1});
        dist[1]=0;
        while(!pq.empty()){
            int dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            for(auto it:adj[node]){
                int adjnode=it.first;
                int wt=it.second;
                if(dis+wt<dist[adjnode]){
                    dist[adjnode]=wt+dis;
                    pq.push({dist[adjnode],adjnode});
                    parent[adjnode]=node;
                }
            }
            
        }
        if(dist[n]==1e9) return {-1};
            vector<int> ans;
            int node=n;
            while(parent[node]!=node){
                ans.push_back(node);
                node=parent[node];
                
            }
            ans.push_back(1);
            reverse(ans.begin(),ans.end());
            // Calculate total distance
int total_dist = 0;
for (int i = 1; i < ans.size(); i++) {
    int u = ans[i - 1];
    int v = ans[i];
    for (auto& edge : adj[u]) {
        if (edge.first == v) {
            total_dist += edge.second;
            break;
        }
    }
}

// Insert total distance at the beginning
ans.insert(ans.begin(), total_dist);
return ans;
    }
};


//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends