class Solution {
public:
    int findrow(vector<vector<int>>& mat, int n, int col) {
        int maxRow = 0;
        for (int i = 1; i < n; i++) {
            if (mat[i][col] > mat[maxRow][col]) {
                maxRow = i;
            }
        }
        return maxRow;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0, high = m - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            int row = findrow(mat, n, mid);

            int left = (mid > 0) ? mat[row][mid - 1] : -1;
            int right = (mid < m - 1) ? mat[row][mid + 1] : -1;

            if (mat[row][mid] >= left && mat[row][mid] >= right) {
                return {row, mid};
            } else if (left > mat[row][mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return {-1, -1}; // Shouldn't be reached with valid input
    }
};
