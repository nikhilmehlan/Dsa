class Solution {
public:
    // int helper(int n,vector<int>& nums,vector<int>& dp){
    //     if(n==0) return nums[n];
    //     if(n<0) return 0;
    //     // pick
    //     if(dp[n]!=-1) return dp[n];
    //     int pick=nums[n]+helper(n-2,nums,dp);
    //     int notpick=helper(n-1,nums,dp);

    //     return dp[n]=max(pick,notpick);

    // }
    int rob(vector<int>& nums) {
        int n=nums.size();
        // vector<int> dp(n+1,-1);
        // dp[0]=nums[0];
        // for(int i=1;i<n;i++){
        //     int pick=nums[i];
        //     if(i-2>=0){
        //     pick=nums[i]+dp[i-2];
        //     }
        //     int notpick=dp[i-1];
        //     dp[i]=max(pick,notpick);
        // }
        // return dp[n-1];
        int prev2=0;
        int prev=nums[0];
        if(n==0) return 0;
        if(n==1) return prev;
        for(int i=1;i<n;i++){
            int curri=max(nums[i]+prev2,prev);
            prev2=prev;
            prev=curri;
        }
        return prev;
    }
};