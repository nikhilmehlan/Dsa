// User function Template for C++

class Solution {
  public:

    vector<int> replaceWithRank(vector<int> &arr, int N) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int num:arr){
            pq.push(num);
        }
        int rank=1;
        map<int,int> mpp;
        while(!pq.empty()){
            int num=pq.top();
            pq.pop();
            if(mpp.find(num)==mpp.end()){
                mpp[num]=rank;
                rank++;
            }
        }
        vector<int> result;
        for(int i=0;i<N;i++){
            result.push_back(mpp[arr[i]]);
        }
        return result;
    }
};
