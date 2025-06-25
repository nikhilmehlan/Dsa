class Solution {
  public:
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        int ans = 1;
        int cnt = 1;
        int i = 1, j = 0;

        while (i < n && j < n) {
            if (arr[i] <= dep[j]) {
                cnt++;  // Need more platforms
                i++;
            } else {
                cnt--;  // One train left, free a platform
                j++;
            }
            ans = max(ans, cnt);
        }

        return ans;
    }
};
