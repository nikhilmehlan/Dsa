class Solution {
public:
    int jump(vector<int>& nums) {
        int l=0;
        int r=0;
        int jumps=0;
        int n=nums.size();
        while(r<n-1){
            int far=0;
            for(int i=l;i<=r;i++){
                far=max(far,i+nums[i]);
            }
            jumps++;
            l=r+1;
            r=far;
        }
    return jumps;
    }
};