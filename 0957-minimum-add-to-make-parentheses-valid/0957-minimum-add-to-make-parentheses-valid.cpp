class Solution {
public:
    int minAddToMakeValid(string s) {
        int balance = 0;
        int insertions=0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                balance++;
            else{
                if(balance>0) balance--;
                else insertions++;
            }
        }
        return balance+insertions;
    }
};