class Solution {
public:
    void generate(vector<string>& ans,int n,string str,int lastchar){
        if(str.size()==n){
            ans.push_back(str);
            return;
        }

        generate(ans,n,str+'1','1');
        if(lastchar!='0'){
            generate(ans,n,str+'0','0');
        }
    }
    vector<string> validStrings(int n) {
        vector<string> ans;
        generate(ans,n,"",'1');
        return ans;
    }
};