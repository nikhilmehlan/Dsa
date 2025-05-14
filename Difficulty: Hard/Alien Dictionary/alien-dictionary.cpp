//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

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


//{ Driver Code Starts.

bool validate(const vector<string> &original, const string &order) {
    unordered_map<char, int> mp;
    for (const string &word : original) {
        for (const char &ch : word) {
            mp[ch] = 1;
        }
    }
    for (const char &ch : order) {
        if (mp.find(ch) == mp.end())
            return false;
        mp.erase(ch);
    }
    if (!mp.empty())
        return false;

    for (int i = 0; i < order.size(); i++) {
        mp[order[i]] = i;
    }

    for (int i = 0; i < original.size() - 1; i++) {
        const string &a = original[i];
        const string &b = original[i + 1];
        int k = 0, n = a.size(), m = b.size();
        while (k < n and k < m and a[k] == b[k]) {
            k++;
        }
        if (k < n and k < m and mp[a[k]] > mp[b[k]]) {
            return false;
        }
        if (k != n and k == m) {
            return false;
        }
    }
    return true;
}

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        string curr;
        vector<string> words;
        while (ss >> curr)
            words.push_back(curr);

        vector<string> original = words;

        Solution ob;
        string order = ob.findOrder(words);

        if (order.empty()) {
            cout << "\"\"" << endl;
        } else {
            cout << (validate(original, order) ? "true" : "false") << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends