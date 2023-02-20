class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size() + 1, vector<int> (amount+1,0));
        
        for(int i=0;i<=coins.size();i++){ // rows denotes the coins
            for(int j=0;j<=amount;j++){ // columns denote the amount
                if(j == 0) dp[i][j] = 1; // if amount 0 we can take only one coin
                else if(i==0) dp[i][j] = 0; // if coins are 0 , 0 combinations will be made
                else // we take the value from one cell above + amount -  coins[i-1]
                    dp[i][j] = dp[i-1][j] + (j-coins[i-1] < 0 ? 0 : dp[i][j-coins[i-1]] );
            }
        }
        
        return dp[coins.size()][amount];
    }
};