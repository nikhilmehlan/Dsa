// User function Template for C++

class Solution {
  public:
    string minWindow(string& s1, string& s2) {
        // Write your Code here
        int n = s1.size();
        int m = s2.size();
        int minLen = INT_MAX;
        int startIdx = -1;

        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[0]) continue; // start matching only when s2[0] is found
            int k = 0;
            int j = i;

            // move j forward to find subsequence
            while (j < n) {
                if (s1[j] == s2[k]) {
                    k++;
                    if (k == m) break;
                }
                j++;
            }

            if (k < m) continue; // didn't find full subsequence

            // backtrack to shrink window from right
            int end = j;
            k = m - 1;
            while (j >= i) {
                if (s1[j] == s2[k]) {
                    k--;
                    if (k < 0) break;
                }
                j--;
            }

            if (end - j < minLen) {
                minLen = end - j;
                startIdx = j;
            }
        }

        return startIdx == -1 ? "" : s1.substr(startIdx, minLen+1);
    }
};
