class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cntfresh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else if(grid[i][j]==1){
                    cntfresh++;
                }
            }
        }

        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        int cnt=0;
        int t=0;
        while(!q.empty()){
            auto top=q.front();
            q.pop();
            int row=top.first.first;
            int col=top.first.second;
            int tm=top.second;
            t=max(tm,t);
            for(int i=0;i<4;i++){
                int nr=row+dr[i];
                int nc=col+dc[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1 && vis[nr][nc]!=2){
                    q.push({{nr,nc},tm+1});
                    cnt++;
                    vis[nr][nc]=2;
                }
            }
        }
        if(cnt!=cntfresh) return -1;
        return t;
    }
};