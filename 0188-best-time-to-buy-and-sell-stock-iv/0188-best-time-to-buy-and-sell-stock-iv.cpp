class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int maxTransactions = k;

        vector<vector<int>> ahead(2, vector<int>(maxTransactions + 1, 0));
        vector<vector<int>> curr(2, vector<int>(maxTransactions + 1, 0));

        for(int i = n - 1; i >= 0; i--) {
            for(int buy = 0; buy <= 1; buy++) {
                for(int cap = 1; cap <= maxTransactions; cap++) {
                    if(buy == 0) {
                        curr[buy][cap] = max(-prices[i] + ahead[1][cap],
                                             ahead[0][cap]);
                    } else {
                        curr[buy][cap] = max(prices[i] + ahead[0][cap - 1],
                                             ahead[1][cap]);
                    }
                }
            }
            ahead = curr;
        }

        return ahead[0][maxTransactions];
    }
};