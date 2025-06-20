class MyQueue {
public:
    MyQueue() {
        
    }
    stack<int> in,out;
    void push(int x) {
        while(!in.empty()){
            out.push(in.top());
            in.pop();
        }
        in.push(x);
        while(!out.empty()){
            in.push(out.top());
            out.pop();
        }
    }
    
    int pop() {
        int x=in.top();
        in.pop();
        return x;
    }
    
    int peek() {
        return in.top();
    }
    
    bool empty() {
        return in.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */