class Solution {
public:
    void dfs(int row, int col, int newCol, int iniCol,
             vector<vector<int>>& image, vector<vector<int>>& ans, int delRow[],
             int delCol[]) {
        ans[row][col] = newCol;
        int n = image.size();
        int m = image[0].size();
        for (int i = 0; i < 4; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                image[nrow][ncol] == iniCol && ans[nrow][ncol] != newCol) {
                dfs(nrow, ncol, newCol, iniCol, image, ans, delRow, delCol);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {

        int iniCol = image[sr][sc];
        vector<vector<int>> ans = image;
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        dfs(sr, sc, color, iniCol, image, ans, delRow, delCol);
        return ans;
    }
};