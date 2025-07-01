
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int n = adj.size();
        vector<int> dis(n, 1e9);
        queue<int> q;

        q.push(src);
        dis[src] = 0;

        while (!q.empty()) {
            int top = q.front();
            q.pop();

            for (auto neighbor : adj[top]) {
                if (dis[neighbor] == 1e9) {
                    dis[neighbor] = dis[top] + 1;
                    q.push(neighbor);
                }
            }
        }

        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++) {
            if (dis[i] != 1e9) {
                ans[i] = dis[i];
            }
        }
        return ans;
    }
};  // ✅ End of class Solution

// ✅ Then define main outside the class

