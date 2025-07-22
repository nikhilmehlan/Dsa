class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> seen;
        int left = 0, right = 0;
        int currSum = 0, maxSum = 0;

        while (right < nums.size()) {
            while (seen.count(nums[right])) {
                seen.erase(nums[left]);
                currSum -= nums[left];
                left++;
            }
            seen.insert(nums[right]);
            currSum += nums[right];
            maxSum = max(maxSum, currSum);
            right++;
        }

        return maxSum;
    }
};
