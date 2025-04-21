class Solution {
public:

    int dfs(int l, int r, vector<int>& piles, vector<vector<int>>& dp) {
        if(l>r) {
            return 0;
        }

        if(dp[l][r] != -1) {
            return dp[l][r];
        }

        int even = (r - l) % 2 == 0;

        int left = even ? piles[l] : 0;
        int right = even ? piles[r] : 0;

        dp[l][r] = max(dfs(l+1, r, piles, dp) + left, dfs(l, r-1, piles, dp) + right);

        return dp[l][r];
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int total = accumulate(piles.begin(), piles.end(), 0);

        int aliceScore = dfs(0, n-1, piles, dp);

        return aliceScore > (total - aliceScore);
    }
};