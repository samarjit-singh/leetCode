class Solution {
public:
    int backtrack(int index, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        if(index >= coins.size()) {
            return 0;
        }

        if(amount < 0) {
            return 0;
        }

        if(amount == 0) {
            return 1;
        }

        if(dp[index][amount] != -1) {
            return dp[index][amount];
        }

        int pick = backtrack(index, amount-coins[index], coins, dp);
        int notPick = backtrack(index+1, amount, coins, dp);

        return dp[index][amount] = pick + notPick;

    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        return backtrack(0, amount, coins, dp);
    }
};