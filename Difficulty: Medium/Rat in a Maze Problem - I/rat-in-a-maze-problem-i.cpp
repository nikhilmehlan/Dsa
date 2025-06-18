class Solution {
  public:
    void helper(vector<vector<int>>& maze, int n, vector<string>& ans,
                string move, int i, int j, vector<vector<int>>& vis,
                int dr[], int dc[], string& dir) {
        if(i == n - 1 && j == n - 1) {
            ans.push_back(move);
            return;
        }

        for(int ind = 0; ind < 4; ind++) {
            int ni = i + dr[ind];
            int nj = j + dc[ind];
            if(ni >= 0 && nj >= 0 && ni < n && nj < n &&
               !vis[ni][nj] && maze[ni][nj] == 1) {
                vis[ni][nj] = 1;
                helper(maze, n, ans, move + dir[ind], ni, nj, vis, dr, dc, dir);
                vis[ni][nj] = 0;
            }
        }
    }

    vector<string> ratInMaze(vector<vector<int>>& maze) {
        vector<string> ans;
        int n = maze.size();
        if(maze[0][0] == 0 || maze[n-1][n-1] == 0) return ans;

        vector<vector<int>> vis(n, vector<int>(n, 0));
        // Direction vectors for D, L, R, U
        int dr[] = {1, 0, 0, -1};
        int dc[] = {0, -1, 1, 0};
        string dir = "DLRU";

        vis[0][0] = 1;
        helper(maze, n, ans, "", 0, 0, vis, dr, dc, dir);

        sort(ans.begin(), ans.end());  // Sort lexicographically
        return ans;
    }
};
