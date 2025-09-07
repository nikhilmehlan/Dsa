class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        long long total=0;
        for(int i=0;i<nums.size();i++){
            int mini=nums[i];
            int maxi=nums[i];
            for(int j=i;j<nums.size();j++){
                mini=min(mini,nums[j]);
                maxi=max(maxi,nums[j]);
                total+=(maxi-mini);
            }
        }
        return total;
    }
};