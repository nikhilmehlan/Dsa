class Solution {
public:
      void processDiagonal(int r, int c, bool descending, vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> vals;

        // Step 1: Collect diagonal elements
        int i = r, j = c;
        while (i < n && j < n) {
            vals.push_back(grid[i][j]);
            i++; j++;
        }

        // Step 2: Sort based on rule
        if (descending)
            sort(vals.begin(), vals.end(), greater<int>());
        else
            sort(vals.begin(), vals.end());

        // Step 3: Put elements back into diagonal
        i = r, j = c;
        int idx = 0;
        while (i < n && j < n) {
            grid[i][j] = vals[idx++];
            i++; j++;
        }
    }

    // Main function
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // Process bottom-left diagonals (including main diagonal) → descending
        for (int i = 0; i < n; i++) {
            processDiagonal(i, 0, true, grid);
        }

        // Process top-right diagonals (excluding main diagonal) → ascending
        for (int j = 1; j < n; j++) {
            processDiagonal(0, j, false, grid);
        }

        return grid;
    }
};