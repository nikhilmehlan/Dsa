class Solution {
  public:
    long long int floorSqrt(long long int n) {
        // Your code goes here
        // return sqrt(n);
        long long int low=0;
        long long int high=n;
        long long int ans=1;
        while(low<=high){
            long long int mid=(low+high)/2;
            if(mid*mid<=n){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};