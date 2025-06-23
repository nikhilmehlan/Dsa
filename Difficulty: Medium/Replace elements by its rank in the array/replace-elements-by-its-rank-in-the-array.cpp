// User function Template for C++

class Solution {
  public:

    vector<int> replaceWithRank(vector<int> &arr, int n) {
        map<int,int> mpp;
        vector<int> sorted=arr;
        sort(sorted.begin(),sorted.end());
        int rank=1;
        for(int i=0;i<n;i++){
          if (mpp.find(sorted[i]) == mpp.end()) {
                mpp[sorted[i]] = rank++;
            }  
        }
        vector<int> result;
        for(auto it:arr){
            result.push_back(mpp[it]);
        }
        return result;
    }
};
