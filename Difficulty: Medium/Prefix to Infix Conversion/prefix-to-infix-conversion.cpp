// User function Template for C++

class Solution {
  public:
          bool isop(char c){
        return (c >= 'a' && c <= 'z') || 
               (c >= 'A' && c <= 'Z') || 
               (c >= '0' && c <= '9');
    }
    
    string preToInfix(string exp) {
        // Write your code here
  stack<string> st;
        for (int i = exp.size()-1; i >=0; i--) {
            if (isop(exp[i])) {
                st.push(string(1, exp[i]));
            } else {
                string op1 = st.top(); st.pop();
                string op2 = st.top(); st.pop();
                string temp = "(" + op1 + exp[i] + op2 + ")";
                st.push(temp);
            }
        }
        return st.top();
    }
};