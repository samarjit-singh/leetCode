class Solution {
public:

    vector<pair<int,int>> directions = {{0,1}, {1,0}, {-1,0}, {0,-1}};

    int util(vector<vector<int>>& matrix, vector<vector<int>>& dp, int row, int col) {

        if (dp[row][col] != 1) return dp[row][col];
        
        for(auto dir:directions) {
            int newRow = dir.first + row;
            int newCol = dir.second + col;

            if( newRow >= 0 && newRow < matrix.size() &&
                newCol >= 0 && newCol < matrix[0].size() &&
                matrix[newRow][newCol] > matrix[row][col] ) {
                    int lenght = 1 + util(matrix, dp, newRow, newCol);
                    
                    dp[row][col] = max(dp[row][col], lenght);
            }
        }

        return dp[row][col];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 1));
        int maxLen = 1;

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                maxLen = max(maxLen, util(matrix, dp, i, j));
            }
        }

        return maxLen;

    }
};