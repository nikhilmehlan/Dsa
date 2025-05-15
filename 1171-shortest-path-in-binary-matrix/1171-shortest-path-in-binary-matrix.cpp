class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // Check if start or end is blocked
        if (grid[0][0] != 0 || grid[n-1][n-1] != 0)
            return -1;

        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        dist[0][0] = 1;
        q.push({1, {0, 0}});

        // 8 directions
        int dir[8][2] = {
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, -1},           {0, 1},
            {1, -1},  {1, 0},  {1, 1}
        };

        while (!q.empty()) {
            auto [d, p] = q.front(); q.pop();
            int r = p.first, c = p.second;

            if (r == n - 1 && c == n - 1)
                return d;

            for (auto &[dr, dc] : dir) {
                int nr = r + dr, nc = c + dc;
                if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                    grid[nr][nc] == 0 && d + 1 < dist[nr][nc]) {
                    dist[nr][nc] = d + 1;
                    q.push({d + 1, {nr, nc}});
                }
            }
        }

        return -1;
    }
};
