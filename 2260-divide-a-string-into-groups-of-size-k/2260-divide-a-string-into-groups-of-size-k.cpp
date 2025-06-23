class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        string res = "";
        for (int i = 0; i < s.size(); i++) {
            res += s[i];
            if (res.size() == k) {
                ans.push_back(res);
                res = "";
            }
        }

        // If remaining characters are less than k, pad with fill
        if (!res.empty()) {
            while (res.size() < k) {
                res += fill;
            }
            ans.push_back(res);
        }

        return ans;
    }
};
