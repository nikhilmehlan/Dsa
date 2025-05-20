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
       int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            int pick = nums[i] + dp[i - 2];
            int notpick = dp[i - 1];
            dp[i] = max(pick, notpick);
        }

        return dp[n - 1];
    }
};