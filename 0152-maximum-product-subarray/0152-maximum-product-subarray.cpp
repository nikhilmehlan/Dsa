class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int presum = 1;
        int suffsum = 1;
        int maxi = INT_MIN;
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            if (presum == 0)
                presum = 1;
            if (suffsum == 0)
                suffsum = 1;
            presum *= nums[i];
            suffsum *= nums[n - i - 1];
            maxi = max(maxi, max(presum, suffsum));
        }
        return maxi;
    }
};