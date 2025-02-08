class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxjump=0;
        for(int i=0;i<nums.size();i++){
            if(i>maxjump) return false;
            maxjump=max(maxjump,i+nums[i]);
        }
        return true;
    }
};