class Solution {
public:
    bool possible(vector<int>& arr, int day, int k, int m) {
        int cnt = 0; // Count of consecutive flowers that can be picked
        int nb = 0;  // Number of bouquets formed
        int n = arr.size();

        for(int i = 0; i < n; i++) {
            if(arr[i] <= day) {
                cnt++;
            } else {
                nb += (cnt / k); // Count bouquets that can be formed
                cnt = 0; // Reset count when the flower is not blooming by 'day'
            }
        }
        
        nb += (cnt / k); // Add remaining bouquets that can be formed
        return nb >= m; // True if we can form 'm' or more bouquets
    }

    int minDays(vector<int>& arr, int m, int k) {
         long long val = m * 1ll * k * 1ll;
    int n = arr.size(); //size of the array
    if (val > n) return -1;

        int low = *min_element(arr.begin(), arr.end());
        int high = *max_element(arr.begin(), arr.end());

        while(low <= high) {
            int mid = low + (high - low) / 2; // Safe way to calculate mid
            if(possible(arr, mid, k, m)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};