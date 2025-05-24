class Solution {
public:
    int helper(vector<int>& coins, int amount, int ind, vector<vector<int>>& dp) {
        if (ind == 0) {
            if (amount % coins[0] == 0) return 1;
            else return 0;
        }
        
        if (dp[ind][amount] != -1) return dp[ind][amount];

        int notpick = helper(coins, amount, ind - 1, dp);
        int pick = 0;
        if (coins[ind] <= amount) {
            pick =helper(coins, amount - coins[ind], ind, dp);
        }
        
        return dp[ind][amount] = pick+ notpick;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = helper(coins, amount, n - 1, dp);
        return ans;
    }
};