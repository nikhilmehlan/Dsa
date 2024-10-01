class Solution {
public:
    void rotate(vector<int>& arr, int k) {
        int n = arr.size();
        if (n == 0)
            return;

        // Adjust k to handle cases where k >= n
        k = k % n;
        if (k == 0)
            return;

        // Use std::vector for the temporary array
        vector<int> temp(k);
        
        // Store the last k elements in temp
        for (int i = n - k; i < n; i++) {
            temp[i - (n - k)] = arr[i];
        }
        
        // Shift the remaining elements in arr
        for (int i = n - k - 1; i >= 0; i--) {
            arr[i + k] = arr[i];
        }

        // Copy the elements from temp to the beginning of arr
        for (int i = 0; i < k; i++) {
            arr[i] = temp[i];
        }
    }
};
