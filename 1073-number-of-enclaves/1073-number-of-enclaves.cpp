class Solution {
public:
    void dfs(int r,int c,vector<vector<int>> &mat,vector<vector<int>> &vis,int dr[],int dc[]){
        vis[r][c]=1;
        int n=mat.size();
        int m=mat[0].size();

        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];

            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && mat[nr][nc]==1){
                dfs(nr,nc,mat,vis,dr,dc);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));

        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

        for(int j=0;j<m;j++){

            if(!vis[0][j] && mat[0][j]==1){
                dfs(0,j,mat,vis,dr,dc);
            }
            if(!vis[n-1][j] && mat[n-1][j]==1){
                dfs(n-1,j,mat,vis,dr,dc);
            }
        }
        for(int i=0;i<n;i++){
            
            if(!vis[i][0] && mat[i][0]==1){
                dfs(i,0,mat,vis,dr,dc);
            }
            if(!vis[i][m-1] && mat[i][m-1]==1){
                dfs(i,m-1,mat,vis,dr,dc);
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && mat[i][j]==1){
                    cnt++;
                }
            }
        }
        return cnt;

    }
};