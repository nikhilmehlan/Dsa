//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string preToInfix(string str) {
        // Write your code here
        int i=str.length()-1;
        stack<string> st;
        while(i>=0){
            if((str[i] >='A' && str[i]<='Z') ||
               (str[i] >='a' && str[i]<='z') ||
               (str[i] >='0' && str[i]<='9') ){
                st.push(string(1, str[i]));
               }
              else{
                  string t1=st.top();
                  st.pop();
                  string t2=st.top();
                  st.pop();
                  string res='('+t1+string(1,str[i])+t2+')';
                  st.push(res);
              }
              i--;
        }
        return st.top();
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToInfix(prefix) << endl;

        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends