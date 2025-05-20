class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> count(n + 1, 0); // Use n+1 for easy range updates
        
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            count[l] += 1;
            if (r + 1 < n) count[r + 1] -= 1;
        }
        
        // Convert to prefix sum to get total coverage per index
        for (int i = 1; i < n; ++i) {
            count[i] += count[i - 1];
        }
        
        // Now count[i] is the number of times index i is covered by queries
        for (int i = 0; i < n; ++i) {
            if (nums[i] > count[i]) return false;
        }
        
        return true;
    }
};
