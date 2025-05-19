//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//Position this line where user code will be pasted.
class Solution {
  public:
    void dfs(int node,vector<int>& vis,vector<vector<int>> &adj,stack<int>& st){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,vis,adj,st);
            }
        }
        
        st.push(node);
    }
    void dfs2(int node,vector<int>& vis,vector<vector<int>> &adj){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs2(it,vis,adj);
            }
        }
    }
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        int n=adj.size();
        vector<int> vis(n,0);
        stack<int> st;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,adj,st);
            }
        }
        vector<vector<int>> adjT(n);
        for(int i=0;i<n;i++){
            vis[i]=0;
            for(auto it:adj[i]){
                adjT[it].push_back(i);
            }
        }
        int scc=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            if(!vis[node]){
                scc++;
                dfs2(node,vis,adjT);
            }
        }
        return scc;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.kosaraju(adj) << "\n";

        // cout << "~"
        //      << "\n";
    }

    return 0;
}

// } Driver Code Ends