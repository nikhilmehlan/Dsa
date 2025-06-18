// User function Template for C++

class Solution {
  public:
  void insert(stack<int> &st, int el) {
    if (st.empty()) {
        st.push(el);
        return;
    }
    int top = st.top();
    st.pop();
    insert(st, el);
    st.push(top);
}

    void Reverse(stack<int> &st) {
        if(st.size()<=1) return;
        
        int top=st.top();
        st.pop();
        Reverse(st);
        insert(st,top);
    }
};