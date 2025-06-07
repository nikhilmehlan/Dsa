class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {

            if (nums[i] == 0) {
                cnt++;
            }
        }
        vector<int> temp;
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                temp.push_back(nums[i]);
            }
        }
        while (cnt != 0) {
            temp.push_back(0);
            cnt--;
        }
        for (int i = 0; i < temp.size(); i++) {
            nums[i] = temp[i];
        }
    }
};