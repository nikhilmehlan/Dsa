// Function to find square root
// x: element to find square root
class Solution {
  public:
    int floorSqrt(int n) {
        // Your code goes here
        int low=1;
        int high=n;
        while(low<=high){
            int mid=(low+high)/2;
            if(mid*mid<=n){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return high;
    }
};