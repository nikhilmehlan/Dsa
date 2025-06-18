class Solution {
public:
    void helper(vector<vector<int>>& ans,vector<int>& ds,int k,int n,int start){
        if(k<0 || n<0) return;
        if(k==0 && n==0){
            ans.push_back(ds);
        }
        for(int i=start;i<=9;i++){
            ds.push_back(i);
            helper(ans,ds,k-1,n-i,i+1);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        helper(ans,ds,k,n,1);
        return ans;
    }
};