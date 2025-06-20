class Solution {
  public:
    int prec(char c){
        if(c=='^'){
            return 3;
        }
        else if(c=='/' || c=='*'){
            return 2;
        }
        else if(c=='+' || c=='-'){
            return 1;
        }
        else{
            return -1;
        }
    }
    string infixToPostfix(string& s) {
        // code here
        string result="";
        stack<char> st;
        for(char c:s){
            if(c>='a' && c<='z' || c>='A' && c<='Z' || c>='0' && c<='9'){
                result+=c;
            }
            else if(c=='('){
                st.push(c);
            }
            else if(c==')'){
                while(st.top()!='('){
                    result+=st.top();
                    st.pop();
                }
                st.pop();
            }
            else{
            while(!st.empty() && prec(c)<=prec(st.top())){
                result+=st.top();
                st.pop();
            }
            st.push(c);
        }}
        while(!st.empty()){
             result+=st.top();
                st.pop();
        }
        return result;
    }
};
