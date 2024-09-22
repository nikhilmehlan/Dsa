class Solution {
public:
    void helper(vector<int>& nums,vector<vector<int>>& result,vector<int>& current,int start){
        result.push_back(current);
        
        for(int i=start;i<nums.size();i++){
            current.push_back(nums[i]);
            
            helper(nums,result,current,i+1);
            
            current.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        helper(nums,result,current,0);
        return result;
    }
};