class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        int cnt=0;
        int xr=0;
        map<int,int> mpp;
        mpp[0]=1;
        int n=arr.size();
        for(int i=0;i<n;i++){
            xr=xr^arr[i];
            
            int req=xr^k;
            
            if(mpp.find(req)!=mpp.end()){
                cnt+=mpp[req];
            }
            
            mpp[xr]++;
        }
        return cnt;
    }
};