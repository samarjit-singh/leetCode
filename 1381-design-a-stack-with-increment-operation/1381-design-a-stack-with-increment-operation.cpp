class CustomStack {
public:
    
//     we are customizing the stack using vector
    vector<int> arr;
    
//     maximum variable is used for storing the maximum size
    int maximum;
    
    
    CustomStack(int maxSize) {
        // arr.clear();
        maximum = maxSize;
    }
    
//     simple push function
    void push(int x) {
        if(arr.size()<maximum){
            arr.push_back(x);
        }
    }
    
//     simple pop function
    int pop() {
        
        int val = -1;
        
        if(arr.size() > 0){
            val = arr.back(); // takes the last element from the vector , .back() is a vector method
            arr.pop_back();
        }
        
        return val;
        
    }
    
    void increment(int k, int val) {
        int n = arr.size();
        
//         min(k,n) takes minimum from k and n and run for loop for that many times
        for(int i=0;i<min(k,n);i++){
            arr[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */