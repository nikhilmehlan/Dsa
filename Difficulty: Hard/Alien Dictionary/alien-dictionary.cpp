
class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
         unordered_map<char, vector<char>> adj;
    unordered_map<char, int> indegree;
    
    // Initialize indegree for all characters in all words
    for (auto &word : words) {
        for (char c : word) {
            indegree[c] = 0;
        }
    }

    // Step 1: Build graph
    for (int i = 0; i < words.size() - 1; i++) {
        string w1 = words[i];
        string w2 = words[i + 1];
        int len = min(w1.size(), w2.size());
        bool found = false;

        for (int j = 0; j < len; j++) {
            if (w1[j] != w2[j]) {
                adj[w1[j]].push_back(w2[j]);
                indegree[w2[j]]++;
                found = true;
                break;
            }
        }

        // Edge case: like ["abc", "ab"] → Invalid order
        if (!found && w1.size() > w2.size()) {
            return "";
        }
    }

    // Step 2: Topological sort using Kahn's Algorithm (BFS)
    queue<char> q;
    for (auto &p : indegree) {
        if (p.second == 0)
            q.push(p.first);
    }

    string result;
    while (!q.empty()) {
        char curr = q.front();
        q.pop();
        result += curr;

        for (char neighbor : adj[curr]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0)
                q.push(neighbor);
        }
    }

    // If the result size doesn't match number of unique characters, there's a cycle
    if (result.size() != indegree.size()) return "";

    return result;
    }
};

