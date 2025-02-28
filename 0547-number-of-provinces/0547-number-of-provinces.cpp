class Solution {
public:
    void dfs(int node,vector<vector<int>>& adj,vector<int>& vis){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
    int n=isConnected.size();
        int provinces=0;
        vector<int> vis(isConnected.size(),0);
         vector<vector<int>> adj(n);
        // Convert adjacency matrix to adjacency list
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                }
            }
        }

        for(int i=0;i<isConnected.size();i++){
            if(!vis[i]){
                provinces++;
                dfs(i,adj,vis);
            }
        }
        return provinces;
    }
};