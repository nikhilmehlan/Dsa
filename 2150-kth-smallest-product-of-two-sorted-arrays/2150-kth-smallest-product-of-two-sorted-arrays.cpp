class Solution {
public:
    long long countLessEqual(vector<int>& nums1, vector<int>& nums2, long long x) {
        long long count = 0;
        int m = nums2.size();

        for (int a : nums1) {
            if (a > 0) {
                int l = 0, r = m - 1;
                while (l <= r) {
                    int mid = (l + r) / 2;
                    if ((long long)a * nums2[mid] <= x)
                        l = mid + 1;
                    else
                        r = mid - 1;
                }
                count += l;
            } else if (a < 0) {
                int l = 0, r = m - 1;
                while (l <= r) {
                    int mid = (l + r) / 2;
                    if ((long long)a * nums2[mid] <= x)
                        r = mid - 1;
                    else
                        l = mid + 1;
                }
                count += m - l;
            } else {
                if (x >= 0) count += m;
            }
        }
        return count;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        long long left = -1e10, right = 1e10;
        long long ans = 0;

        while (left <= right) {
            long long mid = (left + right) / 2;
            if (countLessEqual(nums1, nums2, mid) >= k) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};
