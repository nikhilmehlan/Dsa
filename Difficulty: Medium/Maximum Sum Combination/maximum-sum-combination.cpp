class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        sort(A.rbegin(), A.rend());
        sort(B.rbegin(), B.rend());

        priority_queue<pair<int, pair<int, int>>> pq;
        set<pair<int, int>> st;

        pq.push({A[0] + B[0], {0, 0}});
        st.insert({0, 0});

        vector<int> ans;

        while (K-- && !pq.empty()) {
            auto t = pq.top();
            pq.pop();

            int sum = t.first;
            int i = t.second.first;
            int j = t.second.second;

            ans.push_back(sum);

            if (i + 1 < N && st.find({i + 1, j}) == st.end()) {
                pq.push({A[i + 1] + B[j], {i + 1, j}});
                st.insert({i + 1, j}); // ✅ insert after pushing
            }

            if (j + 1 < N && st.find({i, j + 1}) == st.end()) {
                pq.push({A[i] + B[j + 1], {i, j + 1}});
                st.insert({i, j + 1}); // ✅ insert after pushing
            }
        }

        return ans;
    }
};
