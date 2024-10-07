class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = -1;
        int n = nums.size();
        
        // Find the rightmost index which is smaller than its next element
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                index = i;
                break;
            }
        }
        
        // If no such index is found, the permutation is the highest, so reverse it to get the lowest
        if (index == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        // Find the smallest element on the right of 'index' which is greater than nums[index]
        for (int i = n - 1; i > index; i--) {
            if (nums[i] > nums[index]) {
                swap(nums[i], nums[index]);
                break;
            }
        }
        
        // Reverse the elements to the right of 'index'
        reverse(nums.begin() + index + 1, nums.end());
    }
};
