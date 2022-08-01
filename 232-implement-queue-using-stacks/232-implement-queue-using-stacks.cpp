class MyQueue {
public:
    stack<int> st1,st2;
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        if(st2.empty()){  // if st2 is empty we push elemnts from st1 to st2
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }
        int ans;
        ans = st2.top();
        st2.pop();
        return ans;
    }
    
    int peek() { 
       if(!st2.empty()){ // if st2 is not empty return the top elemnt
           return st2.top();
       } else { // else if it is empty push elemnts from st1 to st2 and return the top element
           while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
           return st2.top();
       }
    }
    
    bool empty() {
        if(st2.empty() && st1.empty()){
            return true;
        }
        return false;
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