class Solution {
public:
    int LongestBitonicSequence(int n, vector<int> &nums) {
        vector<int> inc(n, 1), dec(n, 1);

        // LIS from left to right
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i] && inc[j] + 1 > inc[i]) {
                    inc[i] = inc[j] + 1;
                }
            }
        }

        // LIS (decreasing) from right to left
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j > i; --j) {
                if (nums[j] < nums[i] && dec[j] + 1 > dec[i]) {
                    dec[i] = dec[j] + 1;
                }
            }
        }

        // Compute max bitonic length with both inc & dec parts > 1
        int maxLen = 0;
        for (int i = 0; i < n; ++i) {
            if (inc[i] > 1 && dec[i] > 1) {
                maxLen = max(maxLen, inc[i] + dec[i] - 1);
            }
        }

        return maxLen;
    }
};
