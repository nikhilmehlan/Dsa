class Solution {
  public:
    void dfshelp(int node,vector<int>& dfs,vector<vector<int>>& adj,vector<int>& vis){
        vis[node]=1;
        dfs.push_back(node);
        for(auto it:adj[node]){
            if(!vis[it]){
                dfshelp(it,dfs,adj,vis);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n=adj.size();
        vector<int> vis(n,0);
        vector<int> dfs;
        dfshelp(0,dfs,adj,vis);
        return dfs;
    }
};