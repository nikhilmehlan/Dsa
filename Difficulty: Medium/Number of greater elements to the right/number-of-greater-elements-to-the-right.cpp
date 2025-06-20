// User function Template for C++

class Solution {
  public:

    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices) {
        // write your code here
        vector<int> ngecount(n,0);
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=i+1;j<n;j++){
                if(arr[j]>arr[i]){
                    cnt++;
                }
            }
            ngecount[i]=cnt;
        }
        vector<int> result;
        for(auto it:indices){
            result.push_back(ngecount[it]);
        }
        return result;
    }
};