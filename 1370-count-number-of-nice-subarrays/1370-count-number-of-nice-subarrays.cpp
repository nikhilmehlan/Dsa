class Solution {
public:
    int helper(vector<int>& nums, int goal){
         if (goal < 0)
            return 0;
        int r=0;
        int l=0;
        int cnt=0;
        int n=nums.size();
        int sum=0;
        while(r<n){
            sum+=nums[r]%2;
            while(sum>goal){
                sum-=nums[l]%2;
                l++;
            }
            cnt+=(r-l+1);
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return helper(nums,k)-helper(nums,k-1);
    }
};