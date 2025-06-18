class Solution {
public:
    void helper(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& ds, int ind) {
        if(target == 0){
            ans.push_back(ds);
            return;
        }

        for(int i = ind; i < candidates.size(); ++i) {
            // Skip duplicates at the same level
            if(i > ind && candidates[i] == candidates[i - 1]) continue;
            
            if(candidates[i] > target) break; // Early stopping

            ds.push_back(candidates[i]);
            helper(candidates, target - candidates[i], ans, ds, i + 1); // i+1 because each element can be used once
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // Sort first
        vector<vector<int>> ans;
        vector<int> ds;
        helper(candidates, target, ans, ds, 0);
        return ans;
    }
};
