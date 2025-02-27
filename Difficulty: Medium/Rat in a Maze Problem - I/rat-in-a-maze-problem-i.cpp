//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  void solve(int i, int j, vector<vector<int>>& mat, int n, vector<string>& ans, string move, vector<vector<int>>& vis) {
        // Base case: when reaching the bottom-right corner
        if (i == n - 1 && j == n - 1) {
            ans.push_back(move);
            return;
        }

        // Downward move
        if (i + 1 < n && !vis[i + 1][j] && mat[i + 1][j] == 1) {
            vis[i + 1][j] = 1;
            solve(i + 1, j, mat, n, ans, move + 'D', vis);
            vis[i + 1][j] = 0; // Backtrack
        }

        // Left move
        if (j - 1 >= 0 && !vis[i][j - 1] && mat[i][j - 1] == 1) {
            vis[i][j - 1] = 1;
            solve(i, j - 1, mat, n, ans, move + 'L', vis);
            vis[i][j - 1] = 0; // Backtrack
        }

        // Right move
        if (j + 1 < n && !vis[i][j + 1] && mat[i][j + 1] == 1) {
            vis[i][j + 1] = 1;
            solve(i, j + 1, mat, n, ans, move + 'R', vis);
            vis[i][j + 1] = 0; // Backtrack
        }

        // Upward move
        if (i - 1 >= 0 && !vis[i - 1][j] && mat[i - 1][j] == 1) {
            vis[i - 1][j] = 1;
            solve(i - 1, j, mat, n, ans, move + 'U', vis);
            vis[i - 1][j] = 0; // Backtrack
        }
    }

    vector<string> findPath(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<string> ans;

        if (mat[0][0] == 1) {
            vector<vector<int>> vis(n, vector<int>(n, 0)); // Visitation matrix
            string move = "";
            vis[0][0] = 1; // Mark starting point as visited
            solve(0, 0, mat, n, ans, move, vis);
        }

        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends