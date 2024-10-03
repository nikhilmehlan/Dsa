class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int cnt=0;
       int el;
        for(int i=0;i<nums.size();i++){
            if(cnt==0){
                cnt=1;
                el=nums[i];
            }
            else if(nums[i]==el){
                cnt++;
            }
            else{
                cnt--;
            }
        }
    if(cnt>0){
        return el;
    }
    return -1;
    //-------------Better answer-----------------
    //     unordered_map<int,int> mpp;
    //     int n=nums.size();
    //     for(int i=0;i<nums.size();i++){
    //         mpp[nums[i]]++;
    //     }
    //     for(auto it:mpp){
    //         if(it.second>(n/2)){
    //             return it.first;
    //         }
    //     }
    // return -1;
    // }
    }
};