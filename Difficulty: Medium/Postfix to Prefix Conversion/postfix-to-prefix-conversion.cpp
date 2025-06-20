#include <stack>
#include <string>
using namespace std;

class Solution {
  public:
    bool isop(char c){
        return (c >= 'a' && c <= 'z') || 
               (c >= 'A' && c <= 'Z') || 
               (c >= '0' && c <= '9');
    }

    string postToPre(string exp) {
        stack<string> st;
        for (int i = 0; i < exp.size(); i++) {
            if (isop(exp[i])) {
                st.push(string(1, exp[i]));
            } else {
                string op1 = st.top(); st.pop();
                string op2 = st.top(); st.pop();
                string temp = exp[i]+op2+op1;
                st.push(temp);
            }
        }
        return st.top();
    }
};
