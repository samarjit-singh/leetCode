class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> que;
        
        for(int i=1;i<=n;i++){
            que.push(i);
        }
        
        while(que.size()>1){
            int n = k;
            for(n = k;n>1;n--){
                int first = que.front();
                que.pop();
                que.push(first);
            }
            que.pop();
        }
        return que.front();
    }
};