class Solution {
public:
    int maxDepth(string s) {
        int maxi=0;
        int balance=0;
        for(char c:s){
            if(c=='('){
                balance++;
            }
            else if(c==')'){
                balance--;
            }
            maxi=max(maxi,balance);
        }
        return maxi;
    }
};