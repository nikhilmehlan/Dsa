class Solution {
public:
    int total = 0;
    int empty = 0;
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    void dfs(vector<vector<int>>& grid, int x, int y) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == -1)
            return;

        if (grid[x][y] == 2) {
            if (empty == 1) total++;
            return;
        }

        int temp = grid[x][y];
        grid[x][y] = -1;
        empty--;

        for (int i = 0; i < 4; i++) {
            dfs(grid, x + dr[i], y + dc[i]);
        }

        grid[x][y] = temp;
        empty++;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int startX, startY;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] != -1) empty++; // count all non-obstacle cells
                if (grid[i][j] == 1) {
                    startX = i;
                    startY = j;
                }
            }
        }
        dfs(grid, startX, startY);
        return total;
    }
};
