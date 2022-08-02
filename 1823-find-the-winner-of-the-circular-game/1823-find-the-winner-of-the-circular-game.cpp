class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> que; // make a queue
        
        for(int i=1;i<=n;i++){ // push the index inside the queue
            que.push(i);
        }
        
        while(que.size()>1){ // run this while loop till there is only one element inside the queue
            for(int n = k;n>1;n--){
                int first = que.front();
                que.pop();
                que.push(first);
            }
            que.pop();
        }
        return que.front();
    }
};