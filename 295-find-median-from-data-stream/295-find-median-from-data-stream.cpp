class MedianFinder {
public:
    priority_queue<int> maxheap;
    priority_queue<int,vector<int>,greater<int>>minheap;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) { //making of maxheap and minheap
        
        if(maxheap.empty() && minheap.empty()){
            maxheap.push(num);
        } else {
            if(maxheap.top()<num){
                minheap.push(num);
            } else {
                maxheap.push(num);
            }
        }
        
        int n = maxheap.size();
        int m = minheap.size();
        
        if(n-m == 2 || n-m ==-2){
            if(n>m){
                int element = maxheap.top();
                maxheap.pop();
                minheap.push(element);
            } else {
                int element = minheap.top();
                minheap.pop();
                maxheap.push(element);
            }
        }
        
    }
    
    double findMedian() {
        
        int n = maxheap.size();
        int m = minheap.size();
        
        
        if( (n+m) % 2 == 0){
            return ((double)maxheap.top() + (double)minheap.top())/2.0;
        } 
        
        if(n>m)
            return maxheap.top();
        else
            return minheap.top();
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */