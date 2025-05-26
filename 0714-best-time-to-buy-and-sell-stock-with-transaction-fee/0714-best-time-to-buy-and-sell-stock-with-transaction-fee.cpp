class Solution {
public:
    int helper(int i,int buy,vector<int>& prices,vector<vector<int>>& dp,int fee){
        if(i==prices.size()) return 0;

        if(dp[i][buy]!=-1) return dp[i][buy];
        int profit;
        if(buy==0){
            profit=max(-prices[i]+helper(i+1,1,prices,dp,fee),helper(i+1,0,prices,dp,fee));
        }
        else{
            profit=max(prices[i]+helper(i+1,0,prices,dp,fee)-fee,helper(i+1,1,prices,dp,fee));
        }
        return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices,int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return helper(0,0,prices,dp,fee);
    }
};