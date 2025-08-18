class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long maxi = LLONG_MIN;
        
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    long long val = (long long)(nums[i] - nums[j]) * nums[k];
                    maxi = max(maxi, val);
                }
            }
        }
        
        return maxi < 0 ? 0 : maxi;
    }
};
