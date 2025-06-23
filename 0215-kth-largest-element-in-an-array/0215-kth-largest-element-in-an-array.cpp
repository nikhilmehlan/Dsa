class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int it:nums){
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