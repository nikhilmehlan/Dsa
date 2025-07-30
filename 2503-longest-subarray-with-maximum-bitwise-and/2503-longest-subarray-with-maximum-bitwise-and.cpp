class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        int count = 0, longest = 0;

        for (int num : nums) {
            if (num == maxi) {
                count++;
                longest = max(longest, count);
            } else {
                count = 0;
            }
        }

        return longest;
    }
};
