class Solution {
public:
    int findRow(vector<vector<int>>& mat, int n, int m, int col) {
        int maxEle = -1;
        int index = -1;
        for (int i = 0; i < n; i++) {
            if (mat[i][col] > maxEle) {
                maxEle = mat[i][col];
                index = i;
            }
        }
        return index;
    }

public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0;
        int high = m - 1;
        
        while (low <= high) {
            int mid = (low + high) / 2;
            int row = findRow(mat, n, m, mid);
            int left = (mid - 1 >= 0) ? mat[row][mid - 1] : -1;
            int right = (mid + 1 < m) ? mat[row][mid + 1] : -1;
            
            if ((mid == 0 || mat[row][mid] > mat[row][mid - 1]) && 
                (mid == m - 1 || mat[row][mid] > mat[row][mid + 1])) {
                return {row, mid};
            } 
            else if (mid > 0 && mat[row][mid] < mat[row][mid - 1]) {
                high = mid - 1;
            } 
            else {
                low = mid + 1;
            }
        }
        return {-1, -1};
    }
};
