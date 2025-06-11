// User function template for C++
class Solution {
  public:
    // Count of elements less than or equal to x
    int cntsmall(vector<vector<int>> &mat, int n, int x){
        int cnt = 0;
        for(int i = 0; i < n; i++){
            cnt += upper_bound(mat[i].begin(), mat[i].end(), x) - mat[i].begin();
        }
        return cnt;
    }

    int median(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = INT_MAX;
        int high = INT_MIN;

        // Corrected row-based loop
        for(int i = 0; i < n; i++){
            low = min(low, mat[i][0]);
            high = max(high, mat[i][m - 1]);
        }

        int req = (n * m) / 2;
        while(low <= high){
            int mid = (low + high) / 2;
            int cnt = cntsmall(mat, n, mid);

            if(cnt <= req){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return low;
    }
};
