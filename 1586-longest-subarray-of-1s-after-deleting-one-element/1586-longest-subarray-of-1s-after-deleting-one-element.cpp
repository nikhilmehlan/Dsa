class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0;
        int zeros = 0;
        int maxi = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0)
                zeros++;

            while (zeros > 1) {
                if (nums[left] == 0)
                    zeros--;
                left++;
            }

            // subtract 1 because we must delete one element
            maxi = max(maxi, right - left);
        }

        return maxi;
    }
};
