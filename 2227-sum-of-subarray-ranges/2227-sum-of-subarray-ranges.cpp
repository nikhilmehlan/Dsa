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

    long long sumSubarrayMins(vector<int>& arr) {
        long long total = 0;
        vector<int> nse = findnse(arr);
        vector<int> pse = findpse(arr);
        for (int i = 0; i < arr.size(); i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            total += (left * right * arr[i]);
        }
        return total;
    }

    vector<int> findnle(vector<int>& arr) {
        vector<int> nle(arr.size());
        stack<int> st;
        for (int i = arr.size() - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            nle[i] = st.empty() ? arr.size() : st.top(); // Next Larger Element index
            st.push(i);
        }
        return nle;
    }

    vector<int> findple(vector<int>& arr) {
        vector<int> ple(arr.size());
        stack<int> st;
        for (int i = 0; i < arr.size(); i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            ple[i] = st.empty() ? -1 : st.top(); // Previous Larger Element index
            st.push(i);
        }
        return ple;
    }

    long long sumSubarrayMaxs(vector<int>& arr) {
        long long total = 0;
        vector<int> nle = findnle(arr);
        vector<int> ple = findple(arr);
        for (int i = 0; i < arr.size(); i++) {
            long long left = i - ple[i];
            long long right = nle[i] - i;
            total += (left * right * arr[i]);
        }
        return total;
    }

    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }
};
