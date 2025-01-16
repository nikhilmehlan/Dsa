class MyQueue {
public:
    MyQueue() {}
    stack<int> st1;
    stack<int> st2;
    void push(int x) { st1.push(x); }

    int pop() {
        if (st2.empty()) {
            while (st1.size()) {
                st2.push(st1.top());
                st1.pop();
            }
        }
        if (st2.empty())
            return -1;
        int x = st2.top();
        st2.pop();
        return x;
    }

    int peek() {
        if (st2.empty()) {
            while (st1.size()) {
                st2.push(st1.top());
                st1.pop();
            }
        }
        if (st2.empty())
            return -1;
        int x = st2.top();
        return x;
    }

    bool empty() { return st1.empty() && st2.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */