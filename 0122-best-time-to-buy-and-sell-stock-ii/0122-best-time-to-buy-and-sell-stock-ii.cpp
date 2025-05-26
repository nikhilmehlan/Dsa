class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> ahead(2, 0), curr(2, 0);

        for(int i = n - 1; i >= 0; --i) {
            // buy == 0: We can buy
            curr[0] = max(-prices[i] + ahead[1], ahead[0]);
            // buy == 1: We can sell
            curr[1] = max(prices[i] + ahead[0], ahead[1]);

            ahead = curr;
        }

        return ahead[0]; // Initially, we start at index 0 with permission to buy
    }
};
