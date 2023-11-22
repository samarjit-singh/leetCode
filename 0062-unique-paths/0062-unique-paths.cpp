class Solution {
public:
    
    int util(int i,int j,int n,int m,vector<vector<int>>& dp){
        if(i>=n || j>=m) return 0;
        if(i==n-1 && j == m-1) return 1;
        
        if(dp[i][j] != -1) 
            return dp[i][j];
        else {
            return dp[i][j] = util(i+1,j,n,m,dp) + util(i,j+1,n,m,dp);
        } 
        
        
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return util(0,0,n,m,dp);
    }
};