//User function template for C++

class Solution{   
public:
    int upperBound(vector<int> &arr, int x, int n) {
        int low = 0, high = n - 1;
        int ans = n;

        while (low <= high) {
            int mid = (low + high) / 2;
            // Find first element greater than x
            if (arr[mid] > x) {
                ans = mid;
                high = mid - 1;  // Move left to find a smaller index
            } else {
                low = mid + 1;   // Move right
            }
        }
        return ans;
    }

    // Count the number of elements in the matrix less than or equal to x
    int countSmallEqual(vector<vector<int>> &matrix, int m, int n, int x) {
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            cnt += upperBound(matrix[i], x, n);
        }
        return cnt;
    }

    // Function to find the median in the matrix
    int median(vector<vector<int>> &matrix, int m, int n){
        int low = INT_MAX, high = INT_MIN;

        // Determine the minimum and maximum elements in the matrix
        for (int i = 0; i < m; i++) {
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][n - 1]);
        }

        int req = (m * n) / 2;  // The median is the (m*n)/2 th smallest element
        while (low <= high) {
            int mid = (low + high) / 2;
            int smallEqual = countSmallEqual(matrix, m, n, mid);
            
            // If the count of elements <= mid is less than or equal to req, move right
            if (smallEqual <= req) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;  // The median is found here
    }
};