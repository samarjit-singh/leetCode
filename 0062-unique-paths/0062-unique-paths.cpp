class Solution {
public:
    int util(int m, int n, int row, int col, vector<vector<int>>& dp) {
        if(row >= m || col >= n) {
            return 0;
        }
        // reached destination
        if(row == m-1 && col == n-1) {
            return 1;
        }

        if(dp[row][col] != -1) {
            return dp[row][col];
        }

        int right = util(m, n, row, col+1, dp);
        int down = util(m, n, row+1, col, dp);

        dp[row][col] = right+down;

        return right+down;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n , -1));

        return util(m, n, 0, 0, dp);
    }
};