class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
       if (heightMap.empty() || heightMap[0].empty()) return 0;

        int m = heightMap.size(), n = heightMap[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> minHeap;

        // Add all boundary cells to the heap
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    minHeap.push({heightMap[i][j], {i, j}});
                    visited[i][j] = true;
                }
            }
        }

        // Directions for moving up, down, left, right
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int waterTrapped = 0;

        while (!minHeap.empty()) {
            auto [height, cell] = minHeap.top();
            minHeap.pop();
            int x = cell.first, y = cell.second;

            for (auto [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;

                // Check bounds and if the cell is visited
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                    // Calculate water trapped and update the water level
                    waterTrapped += max(0, height - heightMap[nx][ny]);
                    minHeap.push({max(height, heightMap[nx][ny]), {nx, ny}});
                    visited[nx][ny] = true;
                }
            }
        }

        return waterTrapped; 
    }
};