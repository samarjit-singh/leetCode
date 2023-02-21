class Solution {
public:
    
    int util(vector<int>& prices,int i,int k,bool buy, vector<vector<int>> &dp ){
        if(i >= prices.size() || k<=0) return 0;
        
        if(dp[i][buy] != -1) return dp[i][buy];
        
        if(buy){
            return dp[i][buy] = max(-prices[i]+util(prices,i+1,k,!buy,dp),util(prices,i+1,k,buy,dp));
        } else {
            return dp[i][buy] = max(prices[i]+util(prices,i+1,k-1,!buy,dp), util(prices,i+1,k,buy,dp));
        }
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        vector<vector<int>> dp(n,vector<int>(2,-1));
        
//         index , buy/sell , transaction
        return util(prices,0,1,1,dp);
    }
};