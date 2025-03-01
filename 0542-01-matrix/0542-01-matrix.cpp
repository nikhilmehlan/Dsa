class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
                else{
                    vis[i][j]=0;
                }
            }
        }
        
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int steps=q.front().second;
            q.pop();
            dis[row][col]=steps;
            
            for(int i=0;i<4;i++){
                int nr=row+dr[i];
                int nc=col+dc[i];
                
                if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==0){
                    q.push({{nr,nc},steps+1});
                    vis[nr][nc]=1;
                }
            }
        }
        return dis;
    }
};