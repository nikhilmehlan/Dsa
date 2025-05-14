//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  bool dfscheck(vector<vector<int>> &edges,vector<int>& vis,vector<int>& path,int node){
      vis[node]=1;
      path[node]=1;
      for(auto it:edges[node]){
          if(!vis[it]){
              if(dfscheck(edges,vis,path,it)==true) return true;
          }
          else if(path[it]){
              return true;
          }
      }
      path[node]=0;
      return false;
  }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
         vector<vector<int>> adj(V);
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
        }
        vector<int> vis(V,0);
        vector<int> path(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfscheck(adj,vis,path,i)==true) return true;
            }
        }
        return false;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCyclic(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
    }
    return 0;
}
// } Driver Code Ends