class Solution {
  public:
    int cutRod(vector<int> &price) {
        int n = price.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));

        // Base case: first row (rod length 1, used multiple times)
        for(int len = 0; len <= n; len++) {
            dp[0][len] = price[0] * len;
        }

        for(int i = 1; i < n; i++) {
            int rodLength = i + 1;
            for(int len = 0; len <= n; len++) {
                int notpick = dp[i - 1][len];
                int pick = (rodLength <= len) ? price[i] + dp[i][len - rodLength] : INT_MIN;
                dp[i][len] = max(pick, notpick);
            }
        }

        return dp[n - 1][n];
    }
};
