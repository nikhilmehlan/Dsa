class Solution {
private:
    void dfs(int row, int col, vector<vector<char>>& mat,
             vector<vector<int>>& vis, int drow[], int dcol[]) {
                vis[row][col]=1;
                int n=mat.size();
                int m=mat[0].size();
                for(int i=0;i<4;i++){
                    int nr=row+drow[i];
                    int nc=col+dcol[i];

                    if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && mat[nr][nc]=='O'){
                        dfs(nr,nc,mat,vis,drow,dcol);
                    }
                }
             }

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int j = 0; j < m; j++) {
            if (!vis[0][j] && board[0][j] == 'O') {
                dfs(0, j, board, vis, delrow, delcol);
            }
            if (!vis[n - 1][j] && board[n - 1][j] == 'O') {
                dfs(n - 1, j, board, vis, delrow, delcol);
            }
        }
        for (int i = 0; i < n; i++) {

            if (!vis[i][0] && board[i][0] == 'O') {
                dfs(i, 0, board, vis, delrow, delcol);
            }
            if (!vis[i][m - 1] && board[i][m - 1] == 'O') {
                dfs(i, m - 1, board, vis, delrow, delcol);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};