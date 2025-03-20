class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, 0);

        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i=2;i<cost.size();i++) {
            int cost1 = dp[i-2] + cost[i];
            int cost2 = dp[i-1] + cost[i];
            dp[i] = min(cost1, cost2);
        }

        return min(dp[n-1],dp[n-2]);
    }
};