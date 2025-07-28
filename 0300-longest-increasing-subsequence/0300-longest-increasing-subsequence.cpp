class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> prev(n, -1);
        int maxlen = 1;
        int lastindex = 0;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j] && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > maxlen) {
                maxlen = dp[i];
                lastindex = i;
            }
        }

        // Optional: Reconstruct the actual LIS
        vector<int> lis;
        int curr = lastindex;
        while (curr != -1) {
            lis.push_back(nums[curr]);
            curr = prev[curr];
        }
        reverse(lis.begin(), lis.end());

        // Optional: print LIS
        // for (int x : lis) cout << x << " ";
        // cout << endl;

        return maxlen;
    }
};
