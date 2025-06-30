class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        vector<int> bfs;
        int n=adj.size();
        vector<bool> visited(n,false);
        visited[0]=true;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            bfs.push_back(node);
            
            for(int neigh:adj[node]){
                if(!visited[neigh]){
                    visited[neigh]=true;
                    q.push(neigh);
                }
            }
        }
        return bfs;
    }
};