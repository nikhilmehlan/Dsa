class Solution {
public:
    void backtrack(int n, int k, int start, vector<int>& temp, vector<vector<int>>& result){
        if(temp.size() == k){
            result.push_back(temp);
            return;
        }
        
        for(int i = start; i <= n; i++){
            temp.push_back(i);
            backtrack(n, k, i + 1, temp, result);
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k){
        vector<vector<int>> result;
        vector<int> temp;
        backtrack(n, k, 1, temp, result);
        return result;
    }
};