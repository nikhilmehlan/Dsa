class Solution {
public:
    void solve(int index, string num, int target, vector<string>& ans, // Pass by reference
               string curr, long prev, long res) {
        if (index == num.length()) {
            if (res == target) {
                ans.push_back(curr); // Add current expression to answer if it evaluates to the target
            }
            return;
        }
        string st = "";
        long currRes = 0;
        for (int i = index; i < num.length(); i++) {
            // Avoid numbers with leading zeroes
            if (i > index && num[index] == '0')
                break;
            
            st += num[i];
            currRes = currRes * 10 + (num[i] - '0'); // Build the current number

            if (index == 0) {
                // If it's the first number, don't add an operator in front
                solve(i + 1, num, target, ans, st, currRes, currRes);
            } else {
                // Try adding '+'
                solve(i + 1, num, target, ans, curr + '+' + st, currRes, res + currRes);
                // Try adding '-'
                solve(i + 1, num, target, ans, curr + '-' + st, -currRes, res - currRes);
                // Try adding '*'
                solve(i + 1, num, target, ans, curr + '*' + st, prev * currRes, res - prev + (prev * currRes));
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        solve(0, num, target, ans, "", 0, 0); // Start the recursion
        return ans;
    }
};
