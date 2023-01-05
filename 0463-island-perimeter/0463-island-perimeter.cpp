class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int  peri=0;
        int r = grid.size();
        int c = grid[0].size();
        
        for(int i=0;i<r;i++){
            for(int j =0;j<c;j++){
                if(grid[i][j]==0) continue;
                peri += 4;
                if(i>0) peri -= grid[i-1][j];
                if(j>0) peri -= grid[i][j-1];
                if(i<r-1) peri -= grid[i+1][j];
                if(j<c-1) peri -= grid[i][j+1];
            }
        }
        
        return peri;
    }
};