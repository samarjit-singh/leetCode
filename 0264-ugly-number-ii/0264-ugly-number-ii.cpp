class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long,vector<long>,greater<long>> pq;
        pq.push(1);
        long top;
        while(n--){
            top = pq.top();
            while(!pq.empty() and pq.top() == top){
                pq.pop();
            }
            
            pq.push(top*2);
            pq.push(top*3);
            pq.push(top*5);
        }
        return top;
    }
};