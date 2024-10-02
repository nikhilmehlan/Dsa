class Solution {
public:
    void helper(vector<int>& arr,int target,int index,vector<vector<int>>& ans,int n,vector<int>& ds){
        if(index==n){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }
        if(arr[index]<=target){
            ds.push_back(arr[index]);
            helper(arr,target-arr[index],index,ans,n,ds);
            ds.pop_back();
        }
        helper(arr,target,index+1,ans,n,ds);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        int n=candidates.size();
        helper(candidates,target,0,ans,n,ds);
        return ans;
    }
};