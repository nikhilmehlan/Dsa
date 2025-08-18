class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> suffixMax(n);
        
        suffixMax[n-1] = nums[n-1];
        for (int i = n-2; i >= 0; i--) {
            suffixMax[i] = max(nums[i], suffixMax[i+1]);
        }
        
        long long ans = 0;
        int maxLeft = nums[0];
        
        for (int j = 1; j < n-1; j++) {
            long long val = (long long)(maxLeft - nums[j]) * suffixMax[j+1];
            ans = max(ans, val);
            maxLeft = max(maxLeft, nums[j]);
        }
        
        return ans;
    }
};
