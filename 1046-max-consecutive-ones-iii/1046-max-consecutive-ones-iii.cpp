class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0;
        int right=0;
        int maxlen=0;
        int z=0;
        while(right<nums.size()){
            if(nums[right]==0) z++;
            if(z>k){
                if(nums[left]==0) z--;
                left++;
            }
            if(z<=k){
                int len=right-left+1;
                maxlen=max(maxlen,len);

            }
            right++;
        }
        return maxlen;
    }
};