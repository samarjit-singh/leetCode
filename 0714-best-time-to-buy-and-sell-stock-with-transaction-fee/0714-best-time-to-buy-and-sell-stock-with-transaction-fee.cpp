class Solution {
public:
    
    int dfs(int i,int buy,int n,vector<int>& prices,vector<vector<int>>& dp,int fee){
        if(n==i){
            return 0; //nothing to sell or buy
        }
        
        if(dp[i][buy]!=-1) return dp[i][buy];
        
        if(buy){
            return dp[i][buy] = max(-prices[i]+dfs(i+1,0,n,prices,dp,fee), dfs(i+1,1,n,prices,dp,fee));
        }
        
        return dp[i][buy] = max(prices[i]+dfs(i+1,1,n,prices,dp,fee)-fee, dfs(i+1,0,n,prices,dp,fee));
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return dfs(0,1,n,prices,dp,fee);
    }
};