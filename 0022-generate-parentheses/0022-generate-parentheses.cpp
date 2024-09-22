class Solution {
public:
    void helper(int open,int close,int n,string str,vector<string>& result){
        if(str.length()==2*n){
            result.push_back(str);
            return;
        }
        if(open<n){
            helper(open+1,close,n,str+'(',result);
        }
        if(close<open){
            helper(open,close+1,n,str+')',result);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if(n<=0) return result;
        helper(0,0,n,"",result);
        return result;
    }
};