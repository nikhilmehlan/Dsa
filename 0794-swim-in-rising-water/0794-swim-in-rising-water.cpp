class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
         int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        // min-heap: (time, row, col)
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.emplace(grid[0][0], 0, 0);
        visited[0][0] = true;
        
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while (!pq.empty()) {
            auto [time, r, c] = pq.top();
            pq.pop();
            
            if (r == n - 1 && c == n - 1)
                return time;

            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    pq.emplace(max(time, grid[nr][nc]), nr, nc);
                }
            }
        }

        return -1; // Should never reach here if input is valid
    
    }
};