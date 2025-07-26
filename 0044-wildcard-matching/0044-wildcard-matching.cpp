class Solution {
public:
    bool helper(int i, int j, string& s, string& p, vector<vector<int>>& dp) {
        if (i < 0 && j < 0) return true; // both strings are fully matched
        if (i >= 0 && j < 0) return false; // pattern ended but s didn't
        if (i < 0 && j >= 0) { // string ended but pattern may still have *
            for (int k = 0; k <= j; k++) {
                if (p[k] != '*') return false;
            }
            return true;
        }

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == p[j] || p[j] == '?') {
            return dp[i][j] = helper(i - 1, j - 1, s, p, dp);
        }

        if (p[j] == '*') {
            // Two options:
            // 1. Use * to match current character in s -> move i
            // 2. Use * as empty -> move j
            return dp[i][j] = helper(i - 1, j, s, p, dp) || helper(i, j - 1, s, p, dp);
        }

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return helper(n - 1, m - 1, s, p, dp);
    }
};
