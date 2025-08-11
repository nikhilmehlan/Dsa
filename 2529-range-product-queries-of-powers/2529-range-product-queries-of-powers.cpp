class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> answer;
        vector<int> powers;
        
        // Extract powers of two from n's binary representation
        for (int i = 0; i < 31; i++) {
            if (n & (1 << i)) {
                powers.push_back(1 << i);
            }
        }
        
        int mod = 1e9 + 7;
        
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            long long temp = 1;
            for (int k = l; k <= r; k++) {
                temp = (temp * powers[k]) % mod;
            }
            answer.push_back((int)temp);
        }
        
        return answer;
    }
};
