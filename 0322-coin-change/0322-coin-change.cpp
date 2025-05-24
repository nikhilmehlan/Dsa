class Solution {
public:
    int helper(vector<int>& coins, int amount, int ind, vector<vector<int>>& dp) {
        if (ind == 0) {
            if (amount % coins[0] == 0) return amount / coins[0];
            else return 1e9;
        }
        
        if (dp[ind][amount] != -1) return dp[ind][amount];

        int notpick = helper(coins, amount, ind - 1, dp);
        int pick = 1e9;
        if (coins[ind] <= amount) {
            pick = 1 + helper(coins, amount - coins[ind], ind, dp);
        }
        
        return dp[ind][amount] = min(pick, notpick);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = helper(coins, amount, n - 1, dp);
        return ans >= 1e9 ? -1 : ans;
    }
};
