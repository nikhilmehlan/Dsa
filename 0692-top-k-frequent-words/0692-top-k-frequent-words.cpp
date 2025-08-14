class Solution {
public:
    struct Comp {
        bool operator()(const pair<int,string>& a, const pair<int,string>& b) {
            if (a.first == b.first)
                return a.second > b.second; // lexicographically smaller first
            return a.first < b.first; // higher frequency first
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> freq;
        for (auto &w : words) {
            freq[w]++;
        }

        priority_queue<pair<int,string>, vector<pair<int,string>>, Comp> pq;
        for (auto &it : freq) {
            pq.push({it.second, it.first});
        }

        vector<string> ans;
        while (k-- > 0 && !pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
