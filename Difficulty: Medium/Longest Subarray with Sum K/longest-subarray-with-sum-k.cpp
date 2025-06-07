class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size();
        int sum = 0, maxlen = 0;
        unordered_map<int, int> preSum;

        for (int i = 0; i < n; i++) {
            sum += arr[i];

            if (sum == k) {
                maxlen = max(maxlen, i + 1);
            }

            int rem = sum - k;
            if (preSum.find(rem) != preSum.end()) {
                maxlen = max(maxlen, i - preSum[rem]);
            }

            // store only first occurrence
            if (preSum.find(sum) == preSum.end()) {
                preSum[sum] = i;
            }
        }

        return maxlen;
    }
};
