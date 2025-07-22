class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<>>
            pq;
        pq.emplace(grid[0][0], 0, 0);
        visited[0][0] = true;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while (!pq.empty()) {
            auto [time, row, col] = pq.top();
            pq.pop();
            if (row == n - 1 && col == n - 1)
                return time;

            for (int i = 0; i < 4; i++) {
                int nr = row + dr[i];
                int nc = col + dc[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                    !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    pq.emplace(max(grid[nr][nc], time), nr, nc);
                }
            }
        }
        return -1;
    }
};