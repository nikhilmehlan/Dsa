
class Solution {
  public:
    bool isMaxHeap(int arr[], int n) {
        // Your code goes here
        for(int i=0;i<=(n-2)/2;i++){
            int left=2*i+1;
            int right=2*i+2;
            
            if(left<n && arr[left]>arr[i]){
                return false;
            }
            if(right<n && arr[right]>arr[i]){
                return false;
            }
        }
        return true;
    }
};