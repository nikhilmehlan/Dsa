class Solution {
  public:
    bool canwePlace(vector<int> &stalls, int k, int dis) {
        int cnt = 1; // first cow placed at the first stall
        int last = stalls[0];
        for (int i = 1; i < stalls.size(); i++) {
            if (stalls[i] - last >= dis) {
                cnt++;
                last = stalls[i];
            }
        }
        return cnt >= k;
    }

    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end());
        int low = 1;
        int high = stalls.back() - stalls.front();
        int ans = 0;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (canwePlace(stalls, k, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
