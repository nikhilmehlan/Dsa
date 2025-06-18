class Solution {
public:
    void helper(string digits,vector<string>& ans,string output,int ind,string mapping[]){
        if(ind>=digits.size()){
            ans.push_back(output);
            return;
        }
        int number=digits[ind]-'0';
        string val=mapping[number];
        for(int i=0;i<val.size();i++){
            output.push_back(val[i]);
            helper(digits,ans,output,ind+1,mapping);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>  ans;
        string output="";
        if(digits.size()==0) return ans;
        int ind=0;
        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        helper(digits,ans,output,ind,mapping);
        return ans;
    }
};