class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> prev(n,-1);
        int maxlen=1;
        int last=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 &&  dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                    prev[i]=j;
                }
                if(maxlen<dp[i]){
                    maxlen=dp[i];
                    last=i;
                }
            }
        }
        vector<int> temp;
        while(last!=-1){
            temp.push_back(nums[last]);
            last=prev[last];

        }
        return temp;
    }
};