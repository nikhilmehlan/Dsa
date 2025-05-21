class Solution {
public:
    // int helper(int i,int j,vector<vector<int>>& grid){
    //     if(i==0 && j==0) return grid[i][j];
    //     if(i<0 || j<0) return 1e9;

    //     int up = helper(i - 1, j, grid);
    //     int left = helper(i, j - 1, grid);
    //     return grid[i][j] + min(up, left);
    // }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0)
                    dp[0][0] = grid[i][j];
                else {
                    int up = INT_MAX;
                    int left = INT_MAX;
                    if (i > 0)
                        up = dp[i - 1][j];
                    if (j > 0)
                        left = dp[i][j - 1];
                    dp[i][j] = grid[i][j] + min(up, left);
                }
            }
        }
        return dp[n - 1][m - 1];
    }
};