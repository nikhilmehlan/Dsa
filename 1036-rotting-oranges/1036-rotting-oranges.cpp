class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cntfresh=0;
        queue<pair<pair<int,int>,int>> q;
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
        int dr[]={0,-1,0,1};
        int dc[]={1,0,-1,0};
        int t=0;
        int cnt=0;
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            int row=node.first.first;
            int col=node.first.second;
            int tm=node.second;
            t=max(t,tm);

            for(int i=0;i<4;i++){
                int nr=dr[i]+row;
                int nc=dc[i]+col;

                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc]==1){
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