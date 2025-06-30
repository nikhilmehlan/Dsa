class Solution {
public:
    void dfs(vector<vector<int>>& image, vector<vector<int>>& ans, int sr,
             int sc, int color, int inicol, int dr[], int dc[]) {
        ans[sr][sc] = color;
        int n = image.size();
        int m = image[0].size();
        for (int i = 0; i < 4; i++) {
            int nr = sr + dr[i];
            int nc = sc + dc[i];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                ans[nr][nc] != color && image[nr][nc] == inicol) {
                dfs(image, ans, nr, nc, color, inicol, dr, dc);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int inicol = image[sr][sc];
        if (inicol == color) return image; // No change needed

        vector<vector<int>> ans = image;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        dfs(image, ans, sr, sc, color, inicol, dr, dc);
        return ans;
    }
};
