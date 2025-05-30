class Solution {
public:
    int helper(int i, vector<int>& arr, int k, vector<int>& dp){
        int n = arr.size();
        if (i == n) return 0;
        if (dp[i] != -1) return dp[i];

        int len = 0;
        int maxi = INT_MIN;
        int maxAns = INT_MIN;

        for (int j = i; j < min(i + k, n); j++) {
            len++;
            maxi = max(maxi, arr[j]);
            int sum = maxi * len + helper(j + 1, arr, k, dp);
            maxAns = max(maxAns, sum);
        }

        return dp[i] = maxAns;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size(), -1);
        return helper(0, arr, k, dp);
    }
};
