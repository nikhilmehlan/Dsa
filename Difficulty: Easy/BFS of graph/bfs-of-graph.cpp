class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        vector<int> bfs;
        vector<bool> vis(adj.size(),false);
        vis[0]=true;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            bfs.push_back(node);
            for(auto it:adj[node]){
                if(!vis[it]){
                    vis[it] = true;
                    q.push(it);
                }
            }
        }
        return bfs;
    }
};