class MinStack {
public:
    
    stack<int> st, minStack;
    
    MinStack() {
        
    }
    
    void push(int val) {
        if(minStack.empty() || val<=minStack.top()){
            minStack.push(val);
        }
        st.push(val);
    }
    
    void pop() {
        if(st.top() == minStack.top()){
            minStack.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minStack.top();
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