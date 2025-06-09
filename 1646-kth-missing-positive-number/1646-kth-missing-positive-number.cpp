class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int ind = 0;
        int val = 1;
        int ans = 0;
        
        while (k > 0) {
            if (ind < arr.size() && val == arr[ind]) {
                ind++;
            } else {
                k--;
                ans = val;
            }
            val++;
        }

        return ans;
    }
};
