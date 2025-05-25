class Solution {
public:
    int helper(int i, int j, string &s1, string &s2, vector<vector<int>>& dp) {
        if (i < 0 || j < 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s1[i] == s2[j])
            return dp[i][j] = 1 + helper(i - 1, j - 1, s1, s2, dp);

        return dp[i][j] = max(helper(i - 1, j, s1, s2, dp),
                              helper(i, j - 1, s1, s2, dp));
    }

    int longestPalindromeSubseq(string s) {
        string s2 = s;                     // Step 1: Copy the original string
        reverse(s2.begin(), s2.end());     // Step 2: Reverse it
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1)); // Step 3: use n not m
        return helper(n - 1, n - 1, s, s2, dp); // Step 4: Pass dp here
    }
};
