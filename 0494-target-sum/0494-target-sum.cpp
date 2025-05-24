class Solution {
public:
    int helper(int i, vector<int>& arr, int target, vector<vector<int>>& dp) {
        if (i == 0) {
            if (target == 0 && arr[0] == 0) return 2;
            if (target == 0 || arr[0] == target) return 1;
            return 0;
        }

        if (dp[i][target] != -1) return dp[i][target];

        int notpick = helper(i - 1, arr, target, dp);
        int pick = 0;
        if (arr[i] <= target) {
            pick = helper(i - 1, arr, target - arr[i], dp);
        }
        return dp[i][target] = pick + notpick;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        if ((totalSum - target) < 0 || (totalSum - target) % 2 != 0) return 0;

        int subsetSum = (totalSum - target) / 2;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(subsetSum + 1, -1));
        return helper(n - 1, nums, subsetSum, dp);
    }
};
