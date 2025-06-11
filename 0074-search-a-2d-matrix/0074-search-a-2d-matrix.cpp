class Solution {
public:
    bool binary(vector<int>& arr, int target) {
        int low = 0;
        int high = arr.size()-1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] == target)
                return true;
            else if (arr[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool ans=false;
        for(int i=0;i<matrix.size();i++){
            ans=binary(matrix[i],target);
            if(ans==true) break;
        }
    return ans;
    }
};