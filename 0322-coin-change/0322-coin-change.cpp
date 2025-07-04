class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 1e9));

        // Base case: only using the 0th coin
        for (int t = 0; t <= amount; t++) {
            if (t % coins[0] == 0)
                dp[0][t] = t / coins[0];
        }

        for (int ind = 1; ind < n; ind++) {
            for (int t = 0; t <= amount; t++) {
                int notpick = dp[ind - 1][t];
                int pick = 1e9;
                if (coins[ind] <= t) {
                    pick = 1 + dp[ind][t - coins[ind]];
                }
                dp[ind][t] = min(pick, notpick);
            }
        }

        int res = dp[n - 1][amount];
        return res >= 1e9 ? -1 : res;
    }
};
