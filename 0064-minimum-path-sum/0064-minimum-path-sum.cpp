class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int dp[row][col];
        for(int i = row-1;i>=0;i--){
            for(int j=col-1;j>=0;j--){
                if(i==row-1 && j!=col-1){
                    dp[i][j] =  grid[i][j] + dp[i][j+1];
                } else if(i!=row-1 && j==col-1){
                    dp[i][j] = grid[i][j] + dp[i+1][j];
                } else if(i != row-1 && j != col-1){
                    dp[i][j] = grid[i][j] + min(dp[i+1][j],dp[i][j+1]);
                } else {
                    dp[i][j] = grid[i][j];
                }
            }
        }
        
        return dp[0][0];
    }
};