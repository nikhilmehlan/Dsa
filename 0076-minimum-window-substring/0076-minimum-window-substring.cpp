class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<int> hash(256, 0);

        for (int i = 0; i < m; i++) {
            hash[t[i]]++;
        }
        int r = 0, l = 0, cnt = 0, minlen = INT_MAX, si = -1;
        while (r < n) {
            if (hash[s[r]] > 0) {
                cnt++;
            }
            hash[s[r]]--;
            while(cnt == m) {
                if (minlen > r - l + 1) {
                    minlen = r - l + 1;
                    si = l;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0){
                    cnt--;
                }
                l++;
            }
            r++;
        }
        return (si==-1) ? "" : s.substr(si,minlen);
    }
};