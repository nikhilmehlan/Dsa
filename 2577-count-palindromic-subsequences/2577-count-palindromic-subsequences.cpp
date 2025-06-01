class Solution {
public:
    int countPalindromes(string s) {
        const int MOD = 1e9 + 7;
        int n = s.size();

        vector<vector<int>> left(10, vector<int>(10, 0));
        vector<int> countLeft(10, 0);

        vector<vector<int>> right(10, vector<int>(10, 0));
        vector<int> countRight(10, 0);

        // Precompute all right pair frequencies
        for (int i = n - 1; i >= 0; --i) {
            int d = s[i] - '0';
            for (int j = 0; j < 10; ++j)
                right[d][j] += countRight[j];
            countRight[d]++;
        }

        long long ans = 0;
        // Now try each character as the middle character (at index i)
        for (int i = 0; i < n; ++i) {
            int mid = s[i] - '0';

            // Remove current char from right counters (as it's now center)
            countRight[mid]--;
            for (int j = 0; j < 10; ++j)
                right[mid][j] -= countRight[j];

            // For each (a, b) combination, match with (b, a) from right
            for (int a = 0; a < 10; ++a) {
                for (int b = 0; b < 10; ++b) {
                    ans = (ans + 1LL * left[a][b] * right[b][a]) % MOD;
                }
            }

            // Update left frequency counters
            for (int j = 0; j < 10; ++j)
                left[j][mid] += countLeft[j];
            countLeft[mid]++;
        }

        return ans;
    }
};
