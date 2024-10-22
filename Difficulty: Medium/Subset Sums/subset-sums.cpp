//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void helper(vector<int>& arr, int n, int ind, int sum, vector<int>& sumSubset){
        if(ind == n){
            sumSubset.push_back(sum);  // Ensure sum is added to sumSubset in base case
            return;                    // Add return statement to stop further recursion
        }
        
        // Picking the element at index ind
        helper(arr, n, ind + 1, sum + arr[ind], sumSubset);
        
        // Not picking the element at index ind
        helper(arr, n, ind + 1, sum, sumSubset);
    }

    vector<int> subsetSums(vector<int> arr, int n) {
        vector<int> sumSubset;
        helper(arr, n, 0, 0, sumSubset);
        sort(sumSubset.begin(), sumSubset.end());  // Sort the final subset sums
        
        return sumSubset;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans) {
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends