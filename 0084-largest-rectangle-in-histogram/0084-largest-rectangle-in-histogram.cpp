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
        int mini=0;
        for(int i=0;i<heights.size();i++){
            mini=max(mini,(heights[i]*(nse[i]-pse[i]-1)));
        }
        return mini;
    }
};