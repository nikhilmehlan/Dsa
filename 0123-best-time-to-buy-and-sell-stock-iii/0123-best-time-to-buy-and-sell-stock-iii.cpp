class Solution {
public:
    int helper(int ind,int buy,int cap,vector<int>& prices,vector<vector<vector<int>>>& dp){
        if(ind==prices.size() || cap==0) return 0;
        
        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];

        int profit=0;
        if(buy==0){
            profit=max(-prices[ind]+helper(ind+1,1,cap,prices,dp),helper(ind+1,0,cap,prices,dp));
        }else{
            profit=max(prices[ind]+helper(ind+1,0,cap-1,prices,dp),helper(ind+1,1,cap,prices,dp));
            
        }
        return dp[ind][buy][cap]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxT=2;
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(maxT+1,-1)));
        return helper(0,0,maxT,prices,dp);
    }
};