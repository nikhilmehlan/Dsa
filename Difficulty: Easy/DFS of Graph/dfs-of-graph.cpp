class Solution {
  public:
   void dfs(int node,vector<vector<int>>& adj,int vis[],vector<int>& ls){
        vis[node]=1;
        ls.push_back(node);
        for(auto it:adj[node]){
            if(!vis[it]){
                vis[it]=1;
                dfs(it,adj,vis,ls);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n=adj.size();
        int vis[n]={0};
        int start=0;
        vector<int> ls;
        dfs(start,adj,vis,ls);
        return ls;
    }
};