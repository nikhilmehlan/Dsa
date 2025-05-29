class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        
        // Precompute all palindromic substrings
        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i + len - 1 < n; ++i) {
                int j = i + len - 1;
                if (s[i] == s[j] && (len <= 2 || isPal[i+1][j-1])) {
                    isPal[i][j] = true;
                }
            }
        }

        vector<int> dp(n + 1, INT_MAX);
        dp[n] = 0;

        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (isPal[i][j]) {
                    dp[i] = min(dp[i], 1 + dp[j + 1]);
                }
            }
        }

        return dp[0] - 1;
    }
};
