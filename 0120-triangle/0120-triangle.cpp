class Solution {
public:
    // int helper(int i,int j,vector<vector<int>>& triangle, vector<vector<int>>& dp){
    //     if(i==triangle.size()-1){
    //         return dp[i][j]=triangle[i][j];
    //     }
    //     if(dp[i][j]!=-1) return dp[i][j];

    //     int down=helper(i+1,j,triangle,dp);
    //     int diag=helper(i+1,j+1,triangle,dp);
    //     return triangle[i][j]+min(down,diag);
    // }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int j=0;j<n;j++){
            dp[n-1][j]=triangle[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                int down=dp[i+1][j];
                int diag=dp[i+1][j+1];
                dp[i][j]=triangle[i][j]+min(down,diag);
            }
        }
        return dp[0][0];
    }
};