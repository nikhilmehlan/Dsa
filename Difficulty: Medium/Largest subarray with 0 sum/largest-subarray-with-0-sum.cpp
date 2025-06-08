/*You are required to complete this function*/

class Solution {
  public:
    int maxLen(vector<int>& arr) {
        // code here
        int k=0;
        unordered_map<int,int> mpp;
        int sum=0;
        int len=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum==k){
                len=max(len,i+1);
            }
            int rem=sum-k;
            if(mpp.find(rem)!=mpp.end()){
                int l=i-mpp[rem];
                len=max(len,l);
            }
            if(mpp.find(sum)==mpp.end()){
                mpp[sum]=i;
            }
        }
        return len;
    }
};