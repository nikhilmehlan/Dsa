class Solution {
public:
    int trap(vector<int>& arr) {
        int lmax = 0;
        int rmax = 0;
        int total = 0;
        int l = 0;
        int r = arr.size() - 1;
        while (l < r) {
            if (arr[l] <= arr[r]) {
                if (lmax > arr[l]) {
                    total += lmax - arr[l];
                } else {
                    lmax = arr[l];
                }
                l++;
            } else {
                if (rmax > arr[r]) {
                    total += rmax - arr[r];
                } else {
                    rmax = arr[r];
                }
                r--;
            }
        }
        return total;
    }
};