class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0;
        int r = 0;
        int minlen = INT_MAX;
        int sIndex = -1;
        int cnt = 0;
        int m = t.length();
        vector<int> hash(256, 0);
        for (int i = 0; i < t.length(); i++) {
            hash[t[i]]++;
        }
        while (r < s.size()) {
            if (hash[s[r]] > 0) {
                cnt = cnt + 1;
            }
            hash[s[r]]--;
            while (cnt == m) {
                if (r - l + 1 < minlen) {
                    minlen = r - l + 1;
                    sIndex = l;
                }
                hash[s[l]]++;
                if (hash[s[l]] > 0) {
                    cnt = cnt - 1;
                }
                l++;
            }
            r++;
        }
        return sIndex == -1 ? "" : s.substr(sIndex, minlen);
    }
};