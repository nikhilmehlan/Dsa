class Solution {
public:
    // int helper(int i,int j,vector<vector<int>>& mat){
    //     if(j<0 || j>=mat[0].size()) return 1e9;
    //     if(i==0) return mat[0][j];

    //     int u=helper(i-1,j,mat);
    //     int ld=helper(i-1,j-1,mat);
    //     int rd=helper(i-1,j+1,mat);
    //     return mat[i][j]+min(u,min(ld,rd));
    // }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0) dp[i][j]=matrix[i][j];
                else{
                    int u=dp[i-1][j];
                    int ld=1e9;
                    int rd=1e9;
                    if(j>0) ld=dp[i-1][j-1];
                    if(j<m-1) rd=dp[i-1][j+1];
                    dp[i][j]=matrix[i][j]+min(u,min(ld,rd));

                }
            }
        }
            int mini=1e9;
            for(int j=0;j<m;j++){
             mini = min(mini, dp[n-1][j]);

            }
            return mini;
        }
};