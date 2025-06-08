class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        int cnt=0;
        int xr=0;
        map<int,int> mpp;
        mpp[0]=1;
        for(int i=0;i<arr.size();i++){
            xr=xr^arr[i];
            int rem=xr^k;
            
            if(mpp.find(rem)!=mpp.end()){
                cnt+=mpp[rem];
            }
            
            mpp[xr]++;
        }
        return cnt;
    }
};