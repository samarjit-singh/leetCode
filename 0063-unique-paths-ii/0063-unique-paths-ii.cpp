class Solution {
public:

    int backtrack(vector<vector<int>>& obstacleGrid, int m, int n, int row, int col, vector<vector<int>>& dp) {
        if(row >= m || col >= n || obstacleGrid[row][col] == 1) {
            return 0;
        }

        if(row == m-1 && col == n-1) {
            return 1;
        }

        if(dp[row][col] != -1) {
            return dp[row][col];
        }

        int right = backtrack(obstacleGrid, m, n, row, col+1, dp);
        int down = backtrack(obstacleGrid, m, n, row+1, col, dp);

        return dp[row][col] = right+down;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return backtrack(obstacleGrid, m, n, 0, 0, dp);
    }
};