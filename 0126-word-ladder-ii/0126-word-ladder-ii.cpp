class Solution {
public:
    vector<string> words, temp;
    vector<int> grid[502];
    vector<vector<string>> ans;
    int dist[502], start, end;
    bool check(string& s1, string& s2) {
        int ret = 0;
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i])
                ret++;
        }
        if (ret == 1)
            return true;
        else
            return false;
    }
    void precomp() {
        queue<int> q;
        q.push(end);
        dist[end] = 0;
        int a;
        while (!q.empty()) {
            a = q.front();
            q.pop();
            for (int j : grid[a]) {
                if (dist[j] == 1e9) {
                    dist[j] = dist[a] + 1;
                    q.push(j);
                }
            }
        }
    }
    void dfs(int i) {
        if (i == end) {
            ans.push_back(temp);
            return;
        }
        for (int j : grid[i]) {
            if (dist[j] == dist[i] - 1) {
                temp.push_back(words[j]);
                dfs(j);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string>& wordList) {
        words = wordList;
        words.push_back(beginWord);
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if (check(words[i], words[j])) {
                    grid[i].push_back(j);
                    grid[j].push_back(i);
                }
            }
        }
        end = -1;
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == beginWord) {
                start = i;
            }
            if (words[i] == endWord)
                end = i;
        }
        for (int i = 0; i < 502; i++)
            dist[i] = 1e9;
        temp.push_back(words[start]);
        if (end == -1)
            return {};
        precomp();
        if (dist[start] == 1e9)
            return {};
        dfs(start);
        return ans;
    }
};