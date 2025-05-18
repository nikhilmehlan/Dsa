#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class DisjointSet {
public:
    vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);
        if (pu == pv) return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        // 1. Union all connected 1s
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < n; ++col) {
                if (grid[row][col] == 0) continue;
                for (int i = 0; i < 4; ++i) {
                    int nr = row + dr[i];
                    int nc = col + dc[i];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                        int node = row * n + col;
                        int adjNode = nr * n + nc;
                        ds.unionBySize(node, adjNode);
                    }
                }
            }
        }

        int maxSize = 0;

        // 2. Try flipping each 0 and calculate the connected component size
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < n; ++col) {
                if (grid[row][col] == 1) continue;

                set<int> components;
                for (int i = 0; i < 4; ++i) {
                    int nr = row + dr[i];
                    int nc = col + dc[i];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                        int adjNode = nr * n + nc;
                        components.insert(ds.findUPar(adjNode));
                    }
                }

                int totalSize = 1; // Include the flipped cell
                for (int comp : components)
                    totalSize += ds.size[comp];

                maxSize = max(maxSize, totalSize);
            }
        }

        // 3. Handle case where all 1s (no 0 to flip)
        for (int i = 0; i < n * n; ++i)
            maxSize = max(maxSize, ds.size[ds.findUPar(i)]);

        return maxSize;
    }
};
