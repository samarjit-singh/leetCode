class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> heap;
    int tempK;
    KthLargest(int k, vector<int>& nums) {
        tempK = k;
        for(auto x:nums) {
            heap.push(x);
            while(heap.size() > k) {
                heap.pop();
            }
        }
    }
    
    int add(int val) {
        heap.push(val);
        while(heap.size() > tempK) {
            heap.pop();
        }

        return heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */