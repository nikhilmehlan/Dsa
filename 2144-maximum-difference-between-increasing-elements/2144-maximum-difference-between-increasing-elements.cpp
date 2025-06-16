class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int mini = nums[0];
        int maxi = -1;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > mini) {
                maxi = max(maxi, nums[i] - mini);
            } else {
                mini = nums[i];
            }
        }

        return maxi;
    }
};
