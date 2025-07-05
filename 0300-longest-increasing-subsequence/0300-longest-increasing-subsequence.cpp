class Solution {
public:
    int helper(int i, int prev, vector<int>& nums, vector<vector<int>>& dp) {
        if (i == nums.size())
            return 0;
        if (dp[i][prev+1] != -1)
            return dp[i][prev+1];
        int len = helper(i + 1, prev, nums, dp);// notpick
        if (prev == -1 || nums[i] > nums[prev]) {
            len = max(len,1+ helper(i + 1, i, nums, dp));
        }
        return dp[i][prev+1] = len;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return helper(0, -1, nums, dp);
    }
};