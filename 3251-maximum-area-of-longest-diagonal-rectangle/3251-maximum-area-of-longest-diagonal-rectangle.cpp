class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxDiag = INT_MIN;
        int maxArea = 0;

        for (auto &it : dimensions) {
            int len = it[0];
            int wid = it[1];
            int diagSq = len * len + wid * wid; // use diagonal squared
            int area = len * wid;

            if (diagSq > maxDiag) {
                maxDiag = diagSq;
                maxArea = area;
            } else if (diagSq == maxDiag) {
                maxArea = max(maxArea, area);
            }
        }

        return maxArea;
    }
};
