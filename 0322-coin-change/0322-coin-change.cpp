class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        queue<pair<int,int>> q;
        q.push({amount, 0});

        while(!q.empty()){
            auto [currAmount, count] = q.front();
            q.pop();

            if(currAmount == 0) return count;

            for(auto coin:coins){
                if(currAmount-coin >= 0){
                    q.push({currAmount-coin, count+1});
                }
            }
        }

        return -1;
    }
};