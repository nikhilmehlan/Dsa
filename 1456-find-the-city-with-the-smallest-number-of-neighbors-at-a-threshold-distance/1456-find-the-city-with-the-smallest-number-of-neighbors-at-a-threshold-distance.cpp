class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        // Initialize distances with direct edges
        for (auto it : edges) {
            dist[it[0]][it[1]] = it[2];
            dist[it[1]][it[0]] = it[2];
        }

        // Distance from node to itself is 0
        for (int i = 0; i < n; i++) dist[i][i] = 0;

        // Floyd-Warshall Algorithm
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int minReachable = n; // max possible
        int city = -1;

        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (dist[i][j] <= distanceThreshold) {
                    cnt++;
                }
            }
            // If tie, choose the city with the greater index
            if (cnt <= minReachable) {
                minReachable = cnt;
                city = i;
            }
        }

        return city;
    }
};
