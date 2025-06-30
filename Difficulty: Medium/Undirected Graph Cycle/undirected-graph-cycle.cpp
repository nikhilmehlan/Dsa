class Solution {
  public:
    bool bfs(vector<vector<int>>& graph,vector<int>& vis,int node){
        vis[node]=1;
        queue<pair<int,int>> q;
        q.push({node,-1});
        while(!q.empty()){
            auto top=q.front();
            q.pop();
            int x=top.first;
            int parent=top.second;
            for(auto nei:graph[x]){
                if(!vis[nei]){
                    vis[nei]=1;
                    q.push({nei,x});
                }
                else if(nei!=parent){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
         vector<vector<int>> graph(V);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        // return graph;
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                if(bfs(graph,vis,i)){
                    return true;
                }
            }
        }
        return false;
    }
};