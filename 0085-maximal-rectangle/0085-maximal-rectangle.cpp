class Solution {
public:
 vector<int> findnse(vector<int>& arr) {
        vector<int> nse(arr.size());
        stack<int> st;
        for (int i = arr.size() - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? arr.size() : st.top(); // Next Smaller Element index
            st.push(i);
        }
        return nse;
    }
    vector<int> findpse(vector<int>& arr) {
        vector<int> pse(arr.size());
        stack<int> st;
        for (int i = 0; i < arr.size(); i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top(); // Previous Smaller Element index
            st.push(i);
        }
        return pse;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nse=findnse(heights);
        vector<int> pse=findpse(heights);
        int maxi=0;
        for(int i=0;i<heights.size();i++){
            maxi=max(maxi,(heights[i]*(nse[i]-pse[i]-1)));
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> prefix(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            int sum=0;
            for(int i=0;i<n;i++){
                sum+=matrix[i][j]-'0';
                if(matrix[i][j]=='0') sum=0;
                prefix[i][j]=sum;
            }
        }
        int area=0;
        for(int i=0;i<n;i++){
            area=max(area,largestRectangleArea(prefix[i]));
        }
        return area;
    }
};