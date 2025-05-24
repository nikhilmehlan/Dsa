class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(W + 1, 0));

        // Base case: fill first row
        for (int w = wt[0]; w <= W; w++) {
            dp[0][w] = val[0];
        }

        for (int i = 1; i < n; i++) {
            for (int w = 0; w <= W; w++) {
                int notpick = dp[i - 1][w];
                int pick = -1e9;
                if (wt[i] <= w) {
                    pick = val[i] + dp[i - 1][w - wt[i]];
                }
                dp[i][w] = max(pick, notpick);
            }
        }

        return dp[n - 1][W];
    }
};
