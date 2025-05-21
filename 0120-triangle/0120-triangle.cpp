class Solution {
public:
    // int helper(int i,int j,vector<vector<int>>& triangle){
    //     if(i==triangle.size()-1) return triangle[i][j];

    //     int down=helper(i+1,j,triangle);
    //     int dg=helper(i+1,j+1,triangle);
    //     return triangle[i][j]+min(down,dg);
    // }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        // return helper(0,0,triangle);
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int j=0;j<n;j++){
            dp[n-1][j]=triangle[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                int down=dp[i+1][j];
                int dg=dp[i+1][j+1];
                dp[i][j]=triangle[i][j]+min(down,dg);
            }
        }
        return dp[0][0];
    }
};