class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<int, int> mpp;
        int sum = 0, maxlen = 0;

        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];

            // Case 1: Subarray from start to current index
            if (sum == k) {
                maxlen = max(maxlen, i + 1);
            }

            // Case 2: Subarray between some previous index and current
            int rem = sum - k;
            if (mpp.find(rem) != mpp.end()) {
                int len = i - mpp[rem];
                maxlen = max(maxlen, len);
            }

            // Store the first occurrence of the prefix sum
            if (mpp.find(sum) == mpp.end()) {
                mpp[sum] = i;
            }
        }

        return maxlen;
    }
};
