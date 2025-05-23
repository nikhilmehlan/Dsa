class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        if (sum % 2 != 0)
            return false;
        int nsum = sum / 2;
        vector<vector<bool>> dp(n, vector<bool>(nsum + 1, false));
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        if (nums[0] <= nsum) {
            dp[0][nums[0]] = true;
        }
        for (int i = 1; i < n; i++) {
            for (int target = 1; target <= nsum; target++) {
                bool notpick = dp[i - 1][target];
                bool pick = false;
                if (target >= nums[i]) {
                    pick = dp[i - 1][target - nums[i]];
                }
                dp[i][target] = pick || notpick;
            }
        }
        return dp[n - 1][nsum];
    }
};