// User function template for C++

class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto it:arr){
            pq.push(it);
        }
        if(k==1) return pq.top();
        k--;
        while(k>0){
            pq.pop();
            k--;
        }
        return pq.top();
    }
};