class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int, int>> val_idx;

        for (int i = 0; i < n; ++i) {
            val_idx.push_back({nums[i], i});
        }

        // Sort by value descending
        sort(val_idx.begin(), val_idx.end(), [](auto &a, auto &b) {
            return a.first > b.first;
        });

        // Take top k elements
        vector<pair<int, int>> top_k(val_idx.begin(), val_idx.begin() + k);

        // Sort by original index to maintain order
        sort(top_k.begin(), top_k.end(), [](auto &a, auto &b) {
            return a.second < b.second;
        });

        vector<int> ans;
        for (auto &p : top_k) {
            ans.push_back(p.first);
        }
        return ans;
    }
};
