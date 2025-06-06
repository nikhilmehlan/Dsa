class Solution {
public:
       int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long l = 0;
        long r = 0;
        long sum = 0;
        long length = 0;
        while (r < nums.size()) {
            sum += nums[r];
            while (nums[r] * (r - l + 1) > sum + k) {
                sum -= nums[l];
                l++;
            }
            length = max(length, r - l + 1);
            r++;
        }
        return length;
    }
    };
