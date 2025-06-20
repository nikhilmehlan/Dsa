class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto c:s){
            if(c=='(' || c=='[' || c=='{'){
                st.push(c);
            }
            else{
                if(st.empty()) return false;

                char ch=st.top();
                st.pop();
                if((ch=='(' && c==')') || (ch=='{' && c=='}') || (ch=='[' && c==']')){
                    continue;
                }
                else{
                    return false;
                }
            }
        }
        return st.empty();
    }
};