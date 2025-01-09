class MyStack {
public:
    queue<int> s;
    int first;
    MyStack() {
        
    }
    
    void push(int x) {
        first = x;
        s.push(x);
    }
    
    int pop() {
        int n = s.size() - 1;

        while(n--){
            first = s.front();
            s.push(first);
            s.pop();
        }

        int res = s.front();
        s.pop();

        return res;
    }
    
    int top() {
        return first;
    }
    
    bool empty() {
        return s.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */