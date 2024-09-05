class Solution {
public:
    int maxDepth(string s) {
        int balance = 0;
        int maxi = 0;
        for (char c : s) {
            if (c == '(') {
                if (balance > 0) {
                    balance++;
                    maxi = max(balance, maxi);
                }
                if (balance == 0) {
                    balance++;
                    maxi = max(balance, maxi);
                }
            }
            if (c == ')') {
                balance--;
            }
        }
        return maxi;
    }
};