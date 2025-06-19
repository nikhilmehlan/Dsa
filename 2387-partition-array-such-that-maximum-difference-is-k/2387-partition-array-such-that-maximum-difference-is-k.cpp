class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
         sort(nums.begin(), nums.end());

    int count = 0;
    int i = 0;
    int n = nums.size();

    while (i < n) {
        int start = nums[i];
        // Include as many elements as possible in this group
        while (i < n && nums[i] - start <= k) {
            i++;
        }
        count++; // one valid group formed
    }

    return count;
    }
};