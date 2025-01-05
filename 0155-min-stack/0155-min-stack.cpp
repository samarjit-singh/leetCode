class MinStack {
public:
    stack<pair<int,int>> stack;
    MinStack() {
        
    }
    
    void push(int val) {
        if(stack.empty()){
            stack.push({val,val});
        } else {
            int currentMin = stack.top().second;
            stack.push({val, min(val, currentMin)});
        }
    }
    
    void pop() {
        if(!stack.empty()){
            stack.pop();
        }
    }
    
    int top() {
        return stack.top().first;
    }
    
    int getMin() {
        return stack.top().second;
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