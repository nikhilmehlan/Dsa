class Solution {
public:
    int helper(int ind, vector<vector<int>>& dp, int amount,
               vector<int>& coins) {
        if (ind == 0) {
            if (amount % coins[0] == 0) {
                return amount / coins[0];
            } else {
                return 1e9;
            }
        }
        if (dp[ind][amount] != -1)
            return dp[ind][amount];
        int notpick = helper(ind - 1, dp, amount, coins);
        int pick = 1e9;
        if (coins[ind] <= amount) {
            pick = 1 + helper(ind, dp, amount - coins[ind], coins);
        }

        return dp[ind][amount] = min(pick, notpick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = helper(n - 1, dp, amount, coins);
        if (ans >= 1e9)
            return -1;
        return ans;
    }
};