//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int timer=0;
    void dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& vis,
             vector<int>& tin, vector<int>& low, vector<int>& art){
                vis[node]=1;
                tin[node]=low[node]=timer;
                timer++;
                int ch=0;
                for(auto it:adj[node]){
                    if(it == parent) continue;
                    if(!vis[it]){
                        dfs(it,node,adj,vis,tin,low,art);
                        low[node]=min(low[node],low[it]);
                        if(low[it] >= tin[node] && parent!=-1){
                            art[node]=1;
                        }
                        ch++;
                    }
                    else{
                       low[node]=min(low[node],low[it]); 
                    }
                }
                if(parent==-1 && ch>1){
                    art[node]=1;
                }
             }
    vector<int> articulationPoints(int n, vector<vector<int>>& edges) {
        // Code here
         vector<vector<int>> adj(n);
        for (auto it : edges) {
            adj[it[0]].push_back({it[1]});
            adj[it[1]].push_back({it[0]});
        }
        vector<int> vis(n, 0),art(n,-1);
        vector<int> low(n), tin(n);
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,-1,adj,vis,tin,low,art);
            }
        }
        vector<int> result;
        for(int i=0;i<n;i++){
            if(art[i]==1) result.push_back(i);
        }
        if(result.empty()) return {-1};
        return result;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }
        Solution obj;
        vector<int> ans = obj.articulationPoints(V, edges);
        sort(ans.begin(), ans.end());
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends