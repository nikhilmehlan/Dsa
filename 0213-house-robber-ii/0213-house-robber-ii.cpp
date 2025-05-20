class Solution {
public:
    int helper1(vector<int>& nums){
        int n=nums.size();

        vector<int> dp(n,0);
        if(n==0) return 0;
        if(n==1) return nums[0];
        dp[0]=nums[0];
        for(int i=1;i<n-1;i++){
            int pick=nums[i];
            if(i-2>=0){
                pick+=dp[i-2];
            }
            int notpick=dp[i-1];
            dp[i]=max(pick,notpick);
        }
        return dp[n-2];
    }
    int helper2(vector<int>& nums){
        int n=nums.size();

        vector<int> dp(n,0);
        if(n==0) return 0;
        if(n==1) return nums[0];
        dp[1]=nums[1];
        for(int i=2;i<n;i++){
            int pick=nums[i];
            if(i-2>=1){
                pick+=dp[i-2];
            }
            int notpick=dp[i-1];
            dp[i]=max(pick,notpick);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        int rob1=helper1(nums);
        int rob2=helper2(nums);
        return max(rob1,rob2);
    }
};