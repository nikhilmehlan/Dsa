//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int cutRod(vector<int> &price) {
        // code here
    int n=price.size();
    vector<int> dp(n+1,0);
    
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            dp[i]=max(dp[i],price[j]+dp[i-(j+1)]);
        }
    }
    return dp[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;

        cout << ob.cutRod(a) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends