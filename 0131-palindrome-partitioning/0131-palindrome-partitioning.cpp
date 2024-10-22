class Solution {
public:
    bool isPalindrome(string s , int start , int end){
        while(start<=end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    
    void helper(int ind,vector<string>& path,vector<vector<string>>& ans,string s){
        if(ind==s.size()){
            ans.push_back(path);
            return;
        }
        
        for(int i=ind;i<s.size();i++){
            if(isPalindrome(s,ind,i)){
                path.push_back(s.substr(ind,i-ind+1));
                helper(i+1,path,ans,s);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        helper(0,path,ans,s);
        return ans;
    }
};