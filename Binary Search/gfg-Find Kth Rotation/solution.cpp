#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findKRotation(vector<int> &arr)
    {
        // Code Hereint
        int ans = INT_MAX;
        int index = -1;
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr[low] <= arr[high])
            {
                ans = min(ans, arr[low]);
                if (ans == arr[low])
                    index = low;
                break;
            }
            if (arr[low] <= arr[mid])
            {
                ans = min(ans, arr[low]);
                if (ans == arr[low])
                    index = low;
                low = mid + 1;
            }
            else
            {
                ans = min(ans, arr[mid]);
                if (ans == arr[mid])
                    index = mid;
                high = mid - 1;
            }
        }
        return index;
    }
};