class Solution {
public:
    vector<vector<int>> vis; // initialized a visisted vector
    int N,M;
    
    void ok(int mid,int x,int y,vector<vector<int>>& grid){
        if(vis[x][y]!=1 && grid[x][y]<=mid){
            vis[x][y] = 1;
            if(x-1>=0)
                ok(mid,x-1,y,grid);
            if(x+1<N)
                ok(mid,x+1,y,grid);
            if(y-1>=0)
                ok(mid,x,y-1,grid);
            if(y+1<M)
                ok(mid,x,y+1,grid);
        }
    }
    
    int swimInWater(vector<vector<int>>& grid) {
        int low = 0;
        int hi = 50*50;
        int n = grid.size();
        int m = grid[0].size();
        N = n;
        M = m;
        while(low<hi){
            int mid = (low+hi)/2;
//             for every possible mid value make a new visited vector
            vis = vector<vector<int>>(n,vector<int>(m,0));
            ok(mid,0,0,grid);
//            if the last value of the visisted vector is visited 
//             we will make hi as mid
            if(vis[n-1][m-1]==1) 
                hi = mid;
            else 
                low = mid+1;
        }
        return low;
    }
};