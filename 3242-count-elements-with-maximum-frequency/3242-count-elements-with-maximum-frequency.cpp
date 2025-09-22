class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n=nums.size();
        map<int,int> mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        int maxF=0;
        for(auto& pair:mpp){
            maxF=max(maxF,pair.second);
        }
        int total=0;
        for(auto& p:mpp){
            if(p.second==maxF) total+=p.second;
        }
        return total;
    }
};