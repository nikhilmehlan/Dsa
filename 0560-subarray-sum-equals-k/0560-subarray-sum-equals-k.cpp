class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> mpp;
        int presum=0;
        int cnt=0;
        mpp[0]=1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            presum+=nums[i];
            int remove=presum-k;
            cnt+=mpp[remove];
            mpp[presum]+=1;
        }
        return cnt;
    }
};