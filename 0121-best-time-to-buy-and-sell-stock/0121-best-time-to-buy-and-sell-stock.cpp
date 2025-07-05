class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi=0;
        int cost=INT_MAX;
        for(int i=0;i<prices.size();i++){
            cost=min(cost,prices[i]);
            int profit=prices[i]-cost;
            maxi=max(profit,maxi);
        }
        return maxi;
    }
};