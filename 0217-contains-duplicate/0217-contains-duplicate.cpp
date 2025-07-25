class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(auto it:nums){
            if(mpp.find(it)!=mpp.end()) return true;
            mpp[it]++;
        }
        return false;
    }
};