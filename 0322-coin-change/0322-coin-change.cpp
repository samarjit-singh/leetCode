class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0 || coins.size() == 0) return 0;
        
        // int dp[100] = {amount+1}; 
        vector<int> dp(amount+1,amount+1);
        dp[0] = 0;
        
        for(int i=0;i<coins.size();i++){
            for(int j=coins[i];j<=amount;j++){
                dp[j] = min(dp[j], dp[j-coins[i]]+1);
            }
        }
        
        return dp[amount] == amount+1?-1:dp[amount];
    }
};