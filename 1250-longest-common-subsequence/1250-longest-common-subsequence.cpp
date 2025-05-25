class Solution {
public:
    int helper(int i, int j, string& str1, string& str2, vector<vector<int>>& dp) {
        if(i < 0 || j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(str1[i] == str2[j]) {
            return dp[i][j] = 1 + helper(i - 1, j - 1, str1, str2, dp);
        }

        return dp[i][j] = max(helper(i - 1, j, str1, str2, dp), helper(i, j - 1, str1, str2, dp));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int l1 = text1.size();
        int l2 = text2.size();

        vector<vector<int>> dp(l1, vector<int>(l2, -1));
        return helper(l1 - 1, l2 - 1, text1, text2, dp);
    }
};
