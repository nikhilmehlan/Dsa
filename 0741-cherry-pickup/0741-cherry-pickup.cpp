class Solution {
public:
    int solve(int r1, int c1, int r2, vector<vector<int>>& grid,
              vector<vector<vector<int>>>& dp) {
        int n = grid.size();
        int c2 = r1 + c1 - r2; // because steps are equal

        // Out of bounds or thorn
        if (r1 >= n || c1 >= n || r2 >= n || c2 >= n) return -1e9;
        if (grid[r1][c1] == -1 || grid[r2][c2] == -1) return -1e9;

        // Reached the destination
        if (r1 == n-1 && c1 == n-1) return grid[r1][c1];

        if (dp[r1][c1][r2] != -1) return dp[r1][c1][r2];

        int cherries = grid[r1][c1];
        if (r1 != r2 || c1 != c2)  // avoid double counting
            cherries += grid[r2][c2];

        int best = max({solve(r1+1, c1, r2+1, grid, dp),  // A down, B down
                        solve(r1+1, c1, r2,   grid, dp),  // A down, B right
                        solve(r1, c1+1, r2+1, grid, dp),  // A right, B down
                        solve(r1, c1+1, r2,   grid, dp)});// A right, B right

        return dp[r1][c1][r2] = cherries + best;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == -1 || grid[n-1][n-1] == -1) return 0; // no path

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(n, vector<int>(n, -1)));

        return max(0, solve(0,0,0,grid,dp));
    }
};
