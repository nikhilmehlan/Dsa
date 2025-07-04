class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        if ((totalSum - target) < 0 || (totalSum - target) % 2 != 0)
            return 0;

        int subsetSum = (totalSum - target) / 2;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(subsetSum + 1, 0));

        // Base case initialization
         if (nums[0] == 0) {
            dp[0][0] = 2;  // pick or not pick
        } else {
            dp[0][0] = 1;  // only not pick
            if (nums[0] <= subsetSum) {
                dp[0][nums[0]] = 1;  // pick
            }
        }
        for(int i=1;i<n;i++){
            for(int t=0;t<=subsetSum;t++){
                int notpick=dp[i-1][t];
                int pick=0;
                if(nums[i]<=t){
                    pick=dp[i-1][t-nums[i]];
                }
                dp[i][t]=pick+notpick;
            }
        }
        return dp[n-1][subsetSum];
    }
};
