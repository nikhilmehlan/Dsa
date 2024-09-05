class Solution {
public:
    int beautySum(string s) {
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            map<char, int> mpp;
            for (int j = i; j < s.length(); j++) {
                mpp[s[j]]++;
                int least = INT_MAX;
                int most = INT_MIN;
                for (auto it : mpp) {
                    least = min(it.second, least);
                    most = max(it.second, most);
                }
                ans += most - least;
            }
        }
        return ans;
    }
};