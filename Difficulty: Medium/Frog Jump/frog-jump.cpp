class Solution {
  public:
    int helper(int ind,vector<int>& dp, vector<int>& height){
        if(ind == 0) return 0;
        
        if(dp[ind]!=-1) return dp[ind];
        
        int first=helper(ind-1,dp,height)+abs(height[ind]-height[ind-1]);
        int second=INT_MAX;
        if(ind > 1){
            second=helper(ind-2,dp,height)+abs(height[ind]-height[ind-2]);
        }
        return dp[ind]=min(first,second);
    }
    int minCost(vector<int>& height) {
        // Code here
        int n=height.size();
        vector<int> dp(n,-1);
        return helper(n-1,dp,height);
    }
};