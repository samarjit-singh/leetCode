class Solution {
public:
 
    #define ll long long
    #define MOD 1000000007
 
    // Time Complexity:- O(n*m)
    // Space Complexity:- O(n*m)
 
    ll dfs(int x, int y, vector <vector <int>>& grid, vector <vector <ll>>& dp){
        int n = grid.size(), m = grid.back().size();
 
        if(x == n || y == m){
            return 0;
        }
 
        if(dp[x][y] != -1){
            return dp[x][y];
        }
 
        ll ans = 1;
 
        if(x+1<n && grid[x][y] < grid[x+1][y]){
            ans += dfs(x+1, y, grid, dp);
            ans %= MOD;
        }
        if(x-1>=0 && grid[x][y] < grid[x-1][y]){
            ans += dfs(x-1, y, grid, dp);
            ans %= MOD;
        }
        if(y+1<m && grid[x][y] < grid[x][y+1]){
            ans += dfs(x, y+1, grid, dp);
            ans %= MOD;
        }
        if(y-1>=0 && grid[x][y] < grid[x][y-1]){
            ans += dfs(x, y-1, grid, dp);
            ans %= MOD;
        }
 
        return dp[x][y] = ans;
    }
 
    int countPaths(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid.back().size();
 
        ll ans = 0;
        vector <vector <ll>> dp(n, vector <ll>(m, -1));
 
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans += dfs(i, j, grid, dp);
                ans %= MOD;
            }
        }
 
        return ans;
    }
};