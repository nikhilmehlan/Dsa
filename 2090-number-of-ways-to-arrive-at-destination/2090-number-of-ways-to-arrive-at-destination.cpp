class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

        vector<vector<pair<int, int>>> adj(n);
        for (auto it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        int mod = 1e9 + 7;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});  // {distance, node}

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            long long dis = top.first;
            int node = top.second;

            if (dis > dist[node]) continue;  // optimization

            for (auto it : adj[node]) {
                int v = it.first;
                int wt = it.second;

                if (dis + wt < dist[v]) {
                    dist[v] = dis + wt;
                    ways[v] = ways[node];
                    pq.push({dist[v], v});
                } else if (dis + wt == dist[v]) {
                    ways[v] = (ways[v] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1] % mod;
    }
};
