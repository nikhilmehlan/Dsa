class Solution {
public:
    int helper(vector<int>& piles, int mid) {
        int res = 0;
        for (int i = 0; i < piles.size(); i++) {
            res += (piles[i] + mid - 1) / mid; // integer ceiling
        }
        return res;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = INT_MIN;
        for (int el : piles) {
            maxi = max(el, maxi);
        }

        int low = 1;
        int high = maxi;
        while (low <= high) {
            int mid = (low + high) / 2;
            int val = helper(piles, mid);
            if (val <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
