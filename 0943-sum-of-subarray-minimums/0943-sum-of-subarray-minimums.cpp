class Solution {
public:
    vector<int> findnse(vector<int>& arr) {
        vector<int> nse(arr.size());
        stack<int> st;
        for (int i = arr.size() - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? arr.size() : st.top();// Correct logic
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
            pse[i] = st.empty() ? -1 : st.top(); // Corrected from `arr.size()` to `-1`
            st.push(i);        
        }

        return pse;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int total = 0;
        int mod = (int)(1e9 + 7);
        vector<int> nse = findnse(arr);
        vector<int> pse = findpse(arr);
        for (int i = 0; i < arr.size(); i++) {
            int left = i - pse[i];
            int right = nse[i] - i;
            total = (total + (left * right * 1LL * arr[i]) % mod) % mod;
        }
        return total;
    }
};
