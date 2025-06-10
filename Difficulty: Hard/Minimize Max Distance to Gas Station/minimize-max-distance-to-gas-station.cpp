class Solution {
public:
    // Helper function to calculate the number of stations needed
    int helper(const vector<int> &arr, double dist) {
        int n = arr.size();
        int cnt = 0;
        for (int i = 1; i < n; i++) {
            double segmentLength = arr[i] - arr[i - 1];
            int numberInBetween = segmentLength / dist;
            if (segmentLength == numberInBetween * dist) {
                numberInBetween--; // avoid overcounting exact fits
            }
            cnt += numberInBetween;
        }
        return cnt;
    }

    // Function to find the smallest possible maximum distance
    double findSmallestMaxDist(vector<int> &arr, int k) {
        int n = arr.size();
        double low = 0.0;
        double high = 0.0;

        // Calculate initial high as the max distance between consecutive stations
        for (int i = 0; i < n - 1; i++) {
            high = max(high, (double)(arr[i + 1] - arr[i]));
        }

        double diff = 1e-6;
        while (high - low > diff) {
            double mid = (low + high) / 2.0;
            int cnt = helper(arr, mid);
            if (cnt > k) {
                low = mid;
            } else {
                high = mid;
            }
        }

        return high;
    }
};
