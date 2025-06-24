class Solution {
  public:
    vector<int> minPartition(int N) {
        vector<int> ans;
        vector<int> curr = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1}; // Descending order

        for (int i = 0; i < curr.size(); i++) {
            while (N >= curr[i]) {
                N -= curr[i];
                ans.push_back(curr[i]);
            }
        }

        return ans;
    }
};
