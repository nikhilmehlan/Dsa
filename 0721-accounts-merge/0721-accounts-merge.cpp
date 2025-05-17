class DisjointSet {
public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> mapNode; // mail -> parent account index

        // Step 1: Union emails
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];
                if (mapNode.find(mail) == mapNode.end()) {
                    mapNode[mail] = i;
                } else {
                    ds.unionBySize(i, mapNode[mail]);
                }
            }
        }

        // Step 2: Group emails by parent
        vector<vector<string>> mergedMails(n);
        for (auto& it : mapNode) {
            string mail = it.first;
            int node = ds.findUPar(it.second);
            mergedMails[node].push_back(mail);
        }

        // Step 3: Prepare final answer
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (mergedMails[i].empty()) continue;
            sort(mergedMails[i].begin(), mergedMails[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]); // the name
            temp.insert(temp.end(), mergedMails[i].begin(), mergedMails[i].end());
            ans.push_back(temp);
        }

        return ans;
    }
};
