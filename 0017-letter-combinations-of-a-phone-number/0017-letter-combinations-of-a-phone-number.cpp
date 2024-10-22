class Solution {
public:
    void helper(string digits,string output,vector<string>& ans,int ind,string mapping[]){
        if(ind>=digits.length()){
            ans.push_back(output);
            return;
        }
        
        int number=digits[ind]-'0';
        string value=mapping[number];
        for(int i=0;i<value.length();i++){
            output.push_back(value[i]);
            helper(digits,output,ans,ind+1,mapping);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
      vector<string> ans;
        string output="";
        if(digits.length()==0){
            return ans;
        }
        int ind=0;
        
        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
            
        helper(digits,output,ans,ind,mapping);
        
        return ans;
    }
};