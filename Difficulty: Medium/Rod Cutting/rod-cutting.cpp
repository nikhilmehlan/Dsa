class Solution {
  public:
    int cutRod(vector<int> &price) {
        int n = price.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));

        // Correct base case: only using pieces of length 1 (index 0)
        for(int l = 0; l <= n; l++) {
            dp[0][l] = l * price[0];
        }

        for(int i = 1; i < n; i++) {
            int rodLength = i + 1;
            for(int l = 0; l <= n; l++) {
                int notpick = dp[i - 1][l];
                int pick = INT_MIN;
                if (rodLength <= l) {
                    pick = price[i] + dp[i][l - rodLength];
                }
                dp[i][l] = max(pick, notpick);
            }
        }

        return dp[n - 1][n];
    }
};
