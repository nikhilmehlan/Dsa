class Solution {
public:
    void rotate(vector<int>& nums, int k) {
         int n = nums.size();
        k %= n; // Ensure k is within range
        std::rotate(nums.begin(), nums.begin() + n - k, nums.end());
    }
};