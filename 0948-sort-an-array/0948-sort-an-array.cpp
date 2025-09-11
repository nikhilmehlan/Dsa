class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<>> pq;
        for(int i:nums){
            pq.push(i);
        }
        int n=pq.size();
        for(int i=0;i<n;i++){
            nums[i]=pq.top();
            pq.pop();
        }
        return nums;
    }
};