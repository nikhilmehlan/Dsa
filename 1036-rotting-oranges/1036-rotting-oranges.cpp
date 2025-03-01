class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cntfresh=0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else if(grid[i][j]==1){
                    cntfresh++;
                }
            }
        }

        int drow[]={-1,0,+1,0};
        int dcol[]={0,+1,0,-1};
        int t=0;
        int cnt=0;
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int tm=q.front().second;
            t=max(tm,t);
            q.pop();
            for(int i=0;i<4;i++){
                int nR=r+drow[i];
                int nC=c+dcol[i];

                if(nR>=0 && nR<n && nC>=0 && nC<m && grid[nR][nC]==1 && vis[nR][nC]!=2){
                    q.push({{nR,nC},tm+1});
                    vis[nR][nC]=2;
                    cnt++;
                }
            }
        }
        if(cnt!=cntfresh) return -1;

        return t;
    }
};