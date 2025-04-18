class Solution {
public:

    int dfs(int i, int total, vector<int>& stones, int stoneSum, int target, vector<vector<int>>& dp) {
        if(i == stones.size() || total >= target) {
            return abs(total - (stoneSum-total));
        }

        if(dp[i][total] != -1) {
            return dp[i][total];
        }

        return dp[i][total] = min(dfs(i+1, total+stones[i], stones, stoneSum, target, dp), 
                dfs(i+1, total, stones, stoneSum, target,dp));
    }

    int lastStoneWeightII(vector<int>& stones) {
        int stoneSum = accumulate(stones.begin(), stones.end(), 0);
        int target = (stoneSum + 1) / 2;
        vector<vector<int>> dp(stones.size(), vector<int>(target + 1, -1));

        return dfs(0 , 0, stones, stoneSum, target, dp);

    }
};