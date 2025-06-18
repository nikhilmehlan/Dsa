class Solution {
  public:
    bool checkSubsequenceSum(int N, vector<int>& arr, int K) {
        // Code here
         vector<vector<bool>> dp(N + 1, vector<bool>(K + 1, false));

    // Base Case: sum 0 is always possible (empty subset)
    for (int i = 0; i <= N; ++i) {
        dp[i][0] = true;
    }

    // Fill the DP table
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= K; ++j) {
            if (j >= arr[i - 1]) {
                // Include or exclude the current element
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            } else {
                // Exclude the current element
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[N][K];
    }
};