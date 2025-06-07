class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0) pos.push_back(nums[i]);
            else neg.push_back(nums[i]);
        }
        int i=0;
        while(i<pos.size()){
            res.push_back(pos[i]);
            res.push_back(neg[i]);
            i++;
        }
        return res;
    }
};