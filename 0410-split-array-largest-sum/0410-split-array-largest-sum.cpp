class Solution {
public:
int cntArray(vector<int>& nums, int k){
    int cnt=1;
    int sum=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]+sum<=k){
            sum+=nums[i];
        }
        else{
            cnt++;
            sum=nums[i];
        }
    }
    return cnt;
}
public:
    int splitArray(vector<int>& a, int k) {
       int low=*max_element(a.begin(),a.end());
       int high=accumulate(a.begin(),a.end(),0);
        while(low<=high){
            int mid=low+(high-low)/2;
            int val=cntArray(a,mid);
            if(val<=k){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};