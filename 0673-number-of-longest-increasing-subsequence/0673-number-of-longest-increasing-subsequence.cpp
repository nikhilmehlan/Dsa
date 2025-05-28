class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, 1),cnt(n,1);

        int maxi = 1;

        for (int i = 0; i <= n - 1; i++) {

            for (int prev_index = 0; prev_index <= i - 1; prev_index++) {

                if (nums[prev_index] < nums[i] && 1 + dp[prev_index] > dp[i]) {
                    dp[i] = 1 + dp[prev_index];
                    cnt[i]=cnt[prev_index];
                }
                else if(nums[prev_index] < nums[i] && 1 + dp[prev_index] == dp[i]){
                    cnt[i]+=cnt[prev_index];
                }
            }

            if (dp[i] > maxi)
                maxi = dp[i];
        }
        int nos=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxi) nos+=cnt[i];
        }
        return nos;
    }
};