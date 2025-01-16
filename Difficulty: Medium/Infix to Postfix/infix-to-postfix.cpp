//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int priority(char ch) {
        switch(ch) {
            case '^': return 3;
            case '*': 
            case '/': return 2;
            case '+': 
            case '-': return 1;
            default: return -1; // For non-operators
        }
    }
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string& s) {
        // Your code here
        stack<char> st;
        int i=0;
        string ans="";
        int len=s.length();
        
        while(i<len){
            if((s[i] >='A' && s[i]<='Z') ||
               (s[i] >='a' && s[i]<='z') ||
               (s[i] >='0' && s[i]<='9') ){
                   ans=ans+s[i];
               }
            else if(s[i]=='('){
                st.push(s[i]);
            }
            else if(s[i]==')'){
                while(!st.empty() && st.top()!='('){
                    ans=ans+st.top();
                    st.pop();
                }
                st.pop();
            }
            else{
                while(!st.empty() && priority(s[i])<=priority(st.top())){
                    ans=ans+st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
            i++;
        }
        while(!st.empty()){
            ans=ans+st.top();
                    st.pop();
        }
        return ans;
    }
};


//{ Driver Code Starts.
//  Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends