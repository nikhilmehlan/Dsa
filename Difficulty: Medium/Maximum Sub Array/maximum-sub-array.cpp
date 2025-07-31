class Solution {
  public:
    vector<int> findSubarray(vector<int>& arr) {
        int n = arr.size();
        int start = 0, ansStart = -1, ansEnd = -1;
        long long sum = 0, maxSum = -1;
        int i = 0;

        while (i < n) {
            // Skip negative elements
            while (i < n && arr[i] < 0) i++;
            start = i;
            sum = 0;

            // Traverse the subarray of non-negative numbers
            while (i < n && arr[i] >= 0) {
                sum += arr[i];
                i++;
            }

            // Check if this is the best subarray
            if (sum > maxSum || (sum == maxSum && (i - start) > (ansEnd - ansStart))) {
                maxSum = sum;
                ansStart = start;
                ansEnd = i;
            }
        }

        // Prepare result
        vector<int> result;
        if (ansStart == -1) return {-1}; // No non-negative subarray found

        for (int i = ansStart; i < ansEnd; ++i)
            result.push_back(arr[i]);
    if(result.size()==0) result.push_back(-1);
        return result;
    }
};
