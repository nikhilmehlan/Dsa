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

        // Step 1: Union all 1s
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < n; ++col) {
                if (grid[row][col] == 0) continue;
                for (int i = 0; i < 4; ++i) {
                    int nr = row + dr[i], nc = col + dc[i];
                    if (nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nr][nc] == 1) {
                        int node = row * n + col;
                        int adj = nr * n + nc;
                        ds.unionBySize(node, adj);
                    }
                }
            }
        }

        // Step 2: Check for 0s and calculate potential island size
        int maxIsland = 0;
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < n; ++col) {
                if (grid[row][col] == 1) continue;

                set<int> components;
                for (int i = 0; i < 4; ++i) {
                    int nr = row + dr[i], nc = col + dc[i];
                    if (nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nr][nc] == 1) {
                        components.insert(ds.findUPar(nr * n + nc));
                    }
                }

                int totalSize = 1;  // converting this 0 to 1
                for (int comp : components) {
                    totalSize += ds.size[comp];
                }
                maxIsland = max(maxIsland, totalSize);
            }
        }

        // Edge case: No zero exists, so take max of any connected island
        for (int i = 0; i < n * n; ++i) {
            maxIsland = max(maxIsland, ds.size[ds.findUPar(i)]);
        }

        return maxIsland;
    }
};
