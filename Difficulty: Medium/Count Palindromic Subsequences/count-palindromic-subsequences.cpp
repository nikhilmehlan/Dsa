class Solution {
  public:
    /*You are required to complete below method */
    int countPS(string &s) {
        // Your code here
          int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // substrings of length 1
    for (int i = 0; i < n; ++i)
        dp[i][i] = 1;

    // substrings of length >= 2
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;

            if (s[i] == s[j])
                dp[i][j] = dp[i+1][j] + dp[i][j-1] + 1;
            else
                dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
        }
    }

    return dp[0][n-1];
    }
};