class Solution {
public:
    void helper(int start,vector<vector<int>>& ans, vector<int>& ds,int k,int n){
        if(k<0 || n<0){
            return;
        }
        if(k==0 && n==0){
            ans.push_back(ds);
        }
        for(int i=start;i <= 9;i++){
            ds.push_back(i);
            helper(i+1,ans,ds,k-1,n-i);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
       vector<vector<int>> ans;
       vector<int> ds;
        helper(1,ans,ds,k,n);
        return ans;
    }
};