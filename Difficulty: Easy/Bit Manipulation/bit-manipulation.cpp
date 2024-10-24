//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void bitManipulation(int num, int i) {
        // your code here
        i--;
        // cout << (num & (1<<i)) <<" ";
        // this will result is 00000100 as output which is 4
        cout << (num>>i & 1) <<" ";
        cout << (num | (1<<i)) <<" ";
        cout << (num & ~(1<<i));
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n >> i;
        Solution ob;
        ob.bitManipulation(n, i);
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends