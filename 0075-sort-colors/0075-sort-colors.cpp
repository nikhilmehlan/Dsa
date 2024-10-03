class Solution {
public:
    
public:
    void sortColors(vector<int>& nums) {
       int n=nums.size();
       int low=0,mid=0,high=n-1;
      while(mid<=high){
        if(nums[mid]==0){
            std::swap(nums[low],nums[mid]);
            mid++;
            low++;
        }
        else if(nums[mid]==1){
            mid++;
        }
        else{
            std::swap(nums[high],nums[mid]);
            high--;
        }
       }
    }
};