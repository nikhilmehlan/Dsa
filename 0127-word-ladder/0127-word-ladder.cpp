class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        queue<pair<string, int>> q;
        unordered_set<string> s(wordList.begin(), wordList.end());
        s.erase(beginWord);
        q.push({beginWord, 1});
        while (!q.empty()) {
            auto top = q.front();
            q.pop();
            string word = top.first;
            int steps = top.second;
            if (word == endWord)
                return steps;
            for (int i = 0; i < word.size(); i++) {
                char original = word[i];
                for (char x = 'a'; x <= 'z'; x++) {
                    word[i] = x;
                    if (s.find(word) != s.end()) {
                        q.push({word, steps + 1});
                        s.erase(word);
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};