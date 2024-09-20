class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        int low = 1;
        int high = x;
        int ans = 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;  // Avoid potential overflow in (low + high)
            long long square = (long long)mid * mid;  // Cast to long long to avoid overflow
            
            if (square <= x) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
