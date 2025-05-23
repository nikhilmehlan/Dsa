#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long total;
    int n;

    // Generate all possible subset sums with fixed count of elements
    void generateSums(vector<int>& arr, vector<vector<long long>>& result) {
        int len = arr.size();
        for (int mask = 0; mask < (1 << len); ++mask) {
            int count = 0;
            long long sum = 0;
            for (int i = 0; i < len; ++i) {
                if (mask & (1 << i)) {
                    sum += arr[i];
                    count++;
                }
            }
            result[count].push_back(sum);
        }
    }

    int minimumDifference(vector<int>& nums) {
        int size = nums.size();
        n = size / 2;
        vector<int> left(nums.begin(), nums.begin() + n);
        vector<int> right(nums.begin() + n, nums.end());

        // Calculate total sum
        total = accumulate(nums.begin(), nums.end(), 0LL);

        vector<vector<long long>> leftSums(n + 1), rightSums(n + 1);

        // Generate all subset sums grouped by the number of elements in subset
        generateSums(left, leftSums);
        generateSums(right, rightSums);

        // Sort rightSums for binary search
        for (int i = 0; i <= n; ++i) {
            sort(rightSums[i].begin(), rightSums[i].end());
        }

        long long res = LLONG_MAX;

        // For each subset of left half with 'k' elements, match with right subset of 'n - k' elements
        for (int k = 0; k <= n; ++k) {
            for (long long s1 : leftSums[k]) {
                long long target = total / 2 - s1;
                auto& vec = rightSums[n - k];
                auto it = lower_bound(vec.begin(), vec.end(), target);
                
                // Check current and previous (if exists)
                if (it != vec.end()) {
                    long long s2 = *it;
                    long long currentSum = s1 + s2;
                    res = min(res, abs(total - 2 * currentSum));
                }
                if (it != vec.begin()) {
                    long long s2 = *(--it);
                    long long currentSum = s1 + s2;
                    res = min(res, abs(total - 2 * currentSum));
                }
            }
        }

        return (int)res;
    }
};
