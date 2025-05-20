class Solution {
  public:
    int recurr(int n,int last,vector<vector<int>>& arr,vector<vector<int>>& dp){
        if(n==0){
            int maxi=0;
            for(int i=0;i<3;i++){
                if(i!=last){
                    maxi=max(maxi,arr[0][i]);
                }
            }
            return maxi;
        }
        if(dp[n][last]!=-1) return dp[n][last];
        int maxi=0;
        for(int i=0;i<3;i++){
            if(i!=last){
                int points=arr[n][i]+recurr(n-1,i,arr,dp);
                maxi=max(points,maxi);
            }
        }
        return dp[n][last]=maxi;
    }
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(4,-1));
        return recurr(n-1,3,arr,dp);
    }
};