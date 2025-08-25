class Solution {
  public:
    bool safe(int node,int col,vector<int>& color,vector<vector<int>> &graph){
        
        for(auto nei:graph[node]){
            if(color[nei]==col) return false;
        }
        return true;
    }
    bool solve(int node,vector<vector<int>> &graph,int n,int m,vector<int>& color){
        if(node==n) return true;
        
        for(int i=1;i<=m;i++){
            if(safe(node,i,color,graph)){
                color[node]=i;
                if(solve(node+1,graph,n,m,color)) return true;
                color[node]=0;
            }
        }
        return false;
    }
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        // code here
        vector<vector<int>> graph(v);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int w=edges[i][1];
            graph[u].push_back(w);
            graph[w].push_back(u);
        }
        vector<int> color(v,0);
        if (solve(0,graph,v,m,color)) return true;
        return false;
    }
};