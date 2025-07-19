// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> dest) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        if(source==dest) return 0;
        queue<pair<int,pair<int,int>>> q;
        
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[source.first][source.second]=0;
        q.push({0,{source.first,source.second}});
        while(!q.empty()){
            auto val=q.front();
            q.pop();
            int dt=val.first;
            int r=val.second.first;
            int c=val.second.second;
            if(r==dest.first && c==dest.second){
                return dt;
            }
            int dr[]={-1,0,1,0};
            int dc[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int row=r+dr[i];
                int col=c+dc[i];
                
                if(row>=0 && row<n && col>=0 && col<m && grid[row][col]==1 && 
                dt+1<dist[row][col]){
                    dist[row][col]=dt+1;
                    q.push({dt+1,{row,col}});
                }
            }
        }
        return -1;
    }
};
