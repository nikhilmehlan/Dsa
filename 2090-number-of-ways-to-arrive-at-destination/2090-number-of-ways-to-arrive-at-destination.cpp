class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<vector<pair<int, int>>> adj(n);
        
        for (auto it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        vector<long long> dist(n, LLONG_MAX); // Use long long
        vector<int> ways(n, 0);
        int mod = 1e9 + 7;
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            long long dis = it.first;
            int node = it.second;

            for (auto itr : adj[node]) {
                int adjnode = itr.first;
                int wt = itr.second;

                if (dis + wt < dist[adjnode]) {
                    dist[adjnode] = dis + wt;
                    ways[adjnode] = ways[node];
                    pq.push({dist[adjnode], adjnode});
                } else if (dis + wt == dist[adjnode]) {
                    ways[adjnode] = (ways[adjnode] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1] % mod;
    }
};
