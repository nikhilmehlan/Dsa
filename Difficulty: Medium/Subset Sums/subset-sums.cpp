class Solution {
  public:
    void helper(vector<int>& ans,vector<int>& arr,int sum,int ind){
        if(ind==arr.size()){
            ans.push_back(sum);
            return;
        }
        helper(ans,arr,sum+arr[ind],ind+1);
        helper(ans,arr,sum,ind+1);
    }
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        vector<int> ans;
        helper(ans,arr,0,0);
        return ans;
    }
};