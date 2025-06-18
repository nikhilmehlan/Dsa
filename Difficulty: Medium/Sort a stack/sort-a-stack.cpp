// class SortedStack {
// public:
//     stack<int> s;
//     void sort();
// };

void insert(stack<int> &st, int el) {
    if (st.empty() || st.top() <= el) {
        st.push(el);
        return;
    }
    int top = st.top();
    st.pop();
    insert(st, el);
    st.push(top);
}

void SortedStack :: sort() {
    if (s.size() <= 1) return;

    int temp = s.top();
    s.pop();
    sort(); // or SortedStack::sort();
    insert(s, temp);
}
