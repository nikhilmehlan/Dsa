class MinStack {
public:
    MinStack() {
        
    }
    stack<pair<int,int>> st;
    void push(int val) {
       int mini;
       if(st.empty()){
        mini=val;
       }
       else{
        mini=min(val,st.top().second);
       } 
       st.push({val,mini});

    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */