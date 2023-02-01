class Solution {
public:
    
    int dp[55][55][55];
    
    int dfs(vector<vector<int>>& grid,int r1,int c1,int r2,int c2,int n,int m){
        
        c2 = r1+c1-r2; // this is the manhatten distance
        
//        base condition out of bound or if any one reaches the the thorn we cannot move forward and we retrun INTMIN
        if(r1>=n || c1>=m || r2>= n || c2 >=m || grid[r1][c1] == -1 || grid[r2][c2]==-1) return INT_MIN;
        
//         if it reaches the the bottom
        if(r1 == n-1 && c1 == m-1 && r2 == n-1 && c2 == m-1){
            return grid[r1][c1];
        }
        
//         already calculated
        if(dp[r1][c1][r2]!=-1){
            return dp[r1][c1][r2];
        }
        
        int cherry = 0;
        
        if(r1==r2 && c1 == c2){ // if both present at same location we pick only one
            cherry += grid[r1][c1];
        } else { // else we pick both
            cherry += grid[r1][c1] + grid[r2][c2];
        }
        
        int op1 = dfs(grid, r1, c1 + 1, r2, c2 + 1, n, m);
        int op2 = dfs(grid, r1+1, c1 , r2+1, c2, n, m);
        int op3 = dfs(grid, r1, c1 + 1, r2+1, c2 , n, m);
        int op4 = dfs(grid, r1+1, c1 , r2, c2 + 1, n, m);
        
        int maxi = max({op1, op2, op3, op4});
        
        if(maxi == INT_MIN)
        {
            return dp[r1][c1][r2] = maxi;
        }
        
        return dp[r1][c1][r2] = cherry + maxi;
        
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        memset(dp,-1,sizeof(dp));
        int ans = dfs(grid,0,0,0,0,n,m);
        
        return ans == INT_MIN ? 0 : ans;
    }
};