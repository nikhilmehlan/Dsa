

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        
        // Map values to their positions in the matrix
        unordered_map<int, pair<int, int>> valueToPosition;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                valueToPosition[mat[i][j]] = {i, j};
            }
        }
        
        // Arrays to track painted cells in rows and columns
        vector<int> rowPainted(m, 0), colPainted(n, 0);
        
        // Process each value in arr
        for (int i = 0; i < arr.size(); i++) {
            int value = arr[i];
            auto [row, col] = valueToPosition[value];
            
            // Paint the cell
            rowPainted[row]++;
            colPainted[col]++;
            
            // Check if row or column is fully painted
            if (rowPainted[row] == n || colPainted[col] == m) {
                return i;
            }
        }
        
        // If no row or column is completely painted
        return -1;
    }
};
