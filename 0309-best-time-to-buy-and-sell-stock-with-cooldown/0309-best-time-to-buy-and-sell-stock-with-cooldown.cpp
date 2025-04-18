class Solution {
public:

    int dfs(int index, bool buying, vector<int>& prices, vector<vector<int>>& dp) {
        if(index >= prices.size()) {
            return 0;
        }

        if(dp[index][buying] != -1) {
            return dp[index][buying];
        }

        int cooldown = dfs(index+1, buying, prices, dp);

        if(buying) {
            int buy = dfs(index + 1, false, prices, dp) - prices[index];
            dp[index][buying] = max(buy, cooldown);
        } else {
            int sell = dfs(index + 2, true, prices, dp) + prices[index];
            dp[index][buying] = max(sell, cooldown);
        }

        return dp[index][buying];
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return dfs(0, true, prices, dp);
    }
};