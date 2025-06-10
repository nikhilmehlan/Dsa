class Solution {
  public:
    int minRow(vector<vector<int>> &mat) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
           int cnt_max = INT_MAX;
    int index = -1;

    //traverse the mat:
    for (int i = 0; i < n; i++) {
        int cnt_ones = 0;
        for (int j = 0; j < m; j++) {
            cnt_ones += mat[i][j];
        }
        if (cnt_ones < cnt_max) {
            cnt_max = cnt_ones;
            index = i;
        }
    }
    return index+1;
    }
};