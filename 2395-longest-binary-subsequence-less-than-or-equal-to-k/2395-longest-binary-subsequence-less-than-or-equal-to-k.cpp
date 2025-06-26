class Solution {
public:
    int longestSubsequence(string s, int k) {
        int count = 0;
        int n = s.size();
        int bit = 0;
        long long val = 0;

        // Traverse from the right (least significant bit)
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                count++; // 0 doesn't increase value
            } else {
                if (bit < 31) { // avoid overflow
                    if ((val + (1LL << bit)) <= k) {
                        val += (1LL << bit);
                        count++;
                    }
                }
            }
            bit++;
        }
        return count;
    }
};
