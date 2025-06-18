class Solution {
public:
    void helper(int open,int close,vector<string> &ans,int n,string str){
        if(str.size()==2*n){
            ans.push_back(str);
            return;
        }
        if(open<n){
            helper(open+1,close,ans,n,str+'(');
        }
        if(close<open){
            helper(open,close+1,ans,n,str+')');

        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(0,0,ans,n,"");
        return ans;
    }
};