class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        priority_queue<int,vector<int>,greater<int>> pq;
        if(arr.size()<2) return 0;
        for(int it:arr){
            pq.push(it);
        }
        int sum=0;
        while(pq.size()!=1){
            int x=pq.top(); pq.pop();
            int y=pq.top(); pq.pop();
            int cost=x+y;
            sum+=cost;
            pq.push(cost);
        }
        return sum;
    }
};