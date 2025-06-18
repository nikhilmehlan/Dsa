class Solution {
public:
    void helper(vector<int>& arr,int target,vector<vector<int>>& ans,vector<int>& ds,int ind){
        if(ind==arr.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }
        if(arr[ind]<=target){
            ds.push_back(arr[ind]);
            helper(arr,target-arr[ind],ans,ds,ind);
            ds.pop_back();
        }
        helper(arr,target,ans,ds,ind+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        helper(candidates,target,ans,ds,0);
        return ans;
    }
};