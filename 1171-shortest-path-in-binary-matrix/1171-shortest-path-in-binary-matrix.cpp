class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        pair<int, int> source = {0, 0};
        pair<int, int> dest = {n - 1, n - 1};
         if (grid[0][0] != 0 || grid[n-1][n-1] != 0)
            return -1;
        queue<pair<int, pair<int, int>>> q;
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[source.first][source.second] = 1;
        q.push({1, {source.first, source.second}});
        // int dr[]={-1,0,1,0};
        // int dc[]={0,1,0,-1};

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            
            if (r == n - 1 && c == n - 1)
                return dis;
            for (int dr = -1; dr <= 1; dr++) {
                for (int dc = -1; dc <= 1; dc++) {
                    int newr = r + dr;
                    int newc = c + dc;

                    if (newr >= 0 && newr < n && newc >= 0 && newc < m &&
                        grid[newr][newc] == 0 && dis + 1 < dist[newr][newc]) {
                        dist[newr][newc] = dis + 1;
                        if (newr == dest.first && newc == dest.second)
                            return dis + 1;

                        q.push({dis + 1, {newr, newc}});
                    }
                }
            }
        }
            return -1;
        }
    };