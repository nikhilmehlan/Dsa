class Solution {
public:
    bool solve(string s, string p, int i, int j, vector<vector<int>>& dp) {
        // Case 1: Both string and pattern exhausted
        if (i == s.length() && j == p.length())
            return true;

        // Case 2: Pattern exhausted but string remains
        if (j == p.length())
            return false;

        // Case 3: String exhausted but pattern may still be valid
        if (i == s.length()) {
            // Remaining pattern must be like "a*b*c*", i.e., even length and
            // every second char is '*'
            if ((p.size() - j) % 2 != 0) // rem len is odd
                return false;

            for (int k = j + 1; k < p.size();
                 k += 2) { // check for alternate '*'
                if (p[k] != '*')
                    return false;
            }
            return true;
        }

        // Memoization check
        if (dp[i][j] != -1)
            return dp[i][j];

        bool option1 = false;

        // Direct match or '.'
        if (s[i] == p[j] || p[j] == '.') {
            option1 = solve(s, p, i + 1, j + 1, dp);
        }

        // Handle '*'
        bool option2 = false;
        if (j + 1 < p.size() && p[j + 1] == '*') {
            bool notTake = solve(s, p, i, j + 2, dp); // treat x* as empty

            bool take = false;
            if (s[i] == p[j] || p[j] == '.')
                take = solve(s, p, i + 1, j, dp); // consume a char

            option2 = take || notTake;
        }

        return dp[i][j] = option1 || option2;
    }
    bool solveTab(string s, string p, int n, int m) {
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, 0));

        dp[n][m] = true;

        for (int j = 0; j < m; j++) {
            bool flag = true;
            if ((m - j) % 2 != 0) // rem len is odd
                 flag = false;

            for (int k = j + 1; k < p.size();
                 k += 2) { // check for alternate '*'
                if (p[k] != '*')
                    flag = false;
            }
            dp[n][j] = flag;
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                bool option1 = false;

                // If no '*', match one character
                if (i < s.size() && (s[i] == p[j] || p[j] == '.')) {
                    option1 = dp[i + 1][j + 1];
                }

                bool option2 = false;
                if (j + 1 < p.size() && p[j + 1] == '*') {
                    // skip the part of pattern make "a*" as ""
                    bool notTake = dp[i][j + 2];

                    // but if s[i] matches p[j] consume one char from s
                    bool take = false;
                    if (i < s.size() && (s[i] == p[j] || p[j] == '.'))
                        take = dp[i + 1][j];

                    option2 = take || notTake;
                }

                dp[i][j] = option1 || option2;
            }
        }
        return dp[0][0];
    }
    bool solveSpace(string s, string p, int n, int m) {
        vector<bool>ahead(m + 1, 0), curr(m+1,0);

        ahead[m] = true;

        for (int j = 0; j < m; j++) {
            bool flag = true;
            if ((m - j) % 2 != 0) // rem len is odd
                 flag = false;

            for (int k = j + 1; k < p.size();
                 k += 2) { // check for alternate '*'
                if (p[k] != '*')
                    flag = false;
            }
            ahead[j] = flag;
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                bool option1 = false;

                // If no '*', match one character
                if (i < s.size() && (s[i] == p[j] || p[j] == '.')) {
                    option1 = ahead[j + 1];
                }

                bool option2 = false;
                if (j + 1 < p.size() && p[j + 1] == '*') {
                    // skip the part of pattern make "a*" as ""
                    bool notTake = curr[j + 2];

                    // but if s[i] matches p[j] consume one char from s
                    bool take = false;
                    if (i < s.size() && (s[i] == p[j] || p[j] == '.'))
                        take = ahead[j];

                    option2 = take || notTake;
                }

                curr[j] = option1 || option2;
            }
            ahead = curr;
        }
        return ahead[0];
    }
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        // return solve(s, p, 0, 0, dp);
        // return solveTab(s, p, n, m);
        return solveSpace(s,p,n,m);
    }
};