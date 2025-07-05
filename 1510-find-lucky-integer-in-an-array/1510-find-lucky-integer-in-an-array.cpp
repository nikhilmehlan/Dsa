class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int, int> mpp;
        for (int it : arr) {
            mpp[it]++;
        }

        int res = -1;
        for (auto it : mpp) {
            if (it.first == it.second) {
                res = max(res, it.first);
            }
        }
        return res;
    }
};
