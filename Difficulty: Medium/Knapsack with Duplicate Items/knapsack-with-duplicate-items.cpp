// User function Template for C++

class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int W) {
        // code here
        int n=val.size();
        vector<vector<int>> dp(n,vector<int>(W+1,0));
        for (int w = 0; w <= W; w++) {
            if (w >= wt[0])
                dp[0][w] = (w / wt[0]) * val[0];
        }
        for(int i=1;i<n;i++){
            for(int t=0;t<=W;t++){
                int notpick=dp[i-1][t];
                int pick=-1e9;
                if(wt[i]<=t){
                    pick=val[i]+dp[i][t-wt[i]];
                }
                dp[i][t]=max(pick,notpick);
            }
        }
            return dp[n-1][W];
    }
};