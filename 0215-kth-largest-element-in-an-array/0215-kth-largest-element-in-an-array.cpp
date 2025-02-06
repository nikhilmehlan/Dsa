class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int num:nums){
            pq.push(num);
        }
        if(k==1){
            return pq.top();
        }
        for(int i=0;i<k-1;i++){
            pq.pop();
        }
        return pq.top();
    }
};