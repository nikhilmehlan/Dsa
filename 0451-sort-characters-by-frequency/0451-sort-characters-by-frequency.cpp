class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mpp;  // char -> frequency
        for (char c : s) {
            mpp[c]++;
        }

        priority_queue<pair<int, char>> pq;  // max heap by frequency
        for (auto it : mpp) {
            pq.push({it.second, it.first});
        }

        string res;
        while (!pq.empty()) {
            auto top = pq.top();
            res.append(top.first, top.second);  // append 'char' top.first times
            pq.pop();
        }

        return res;
    }
};
