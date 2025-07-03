class Solution {
public:
    int helper(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& grid) {
        if (i < 0 || j < 0)
            return 0;
        if (grid[i][j] == 1)
            return 0;
        if (i == 0 && j == 0)
            return 1;
        if (dp[i][j] != -1)
            return dp[i][j];

        int up = helper(i - 1, j, dp, grid);
        int left = helper(i, j - 1, dp, grid);
        return dp[i][j] = up + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(m - 1, n - 1, dp, obstacleGrid);
    }
};
