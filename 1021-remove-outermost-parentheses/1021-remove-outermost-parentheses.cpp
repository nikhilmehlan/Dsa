class Solution {
public:
    string removeOuterParentheses(string s) {
      //using simple for loop--------------------
      int balance=0;
      string result;
      for(char c: s){
        if(c=='('){
            if(balance>0){
                result+=c;
            }
            balance++;
        }

        if(c==')'){
            balance--;
            if(balance>0){
                result+=c;
            }
        }
      }
      return result;
        // stack<char> st;
        // string result;
        // for (char c : s) {
        //     if (c == '(') {
        //         if (!st.empty()) {
        //             result += c;
        //         }
        //         st.push(c);
        //     }
        //     if (c == ')') {
        //         st.pop();
        //         if (!st.empty()) {
        //             result += c;
        //         }
        //     }
        // }
        // return result;
    }
};