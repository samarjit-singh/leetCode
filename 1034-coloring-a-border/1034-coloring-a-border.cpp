class Solution {
public:
    
    void dfs(int i,int j,vector<vector<int>>& grid,int origin,int color,vector<vector<int>>& temp){
        
        if(i < 0 || i == grid.size() || j < 0 || j == grid[0].size() || grid[i][j] != origin || grid[i][j] == color) 
            return;
        
        grid[i][j] = color;
        
        dfs(i-1,j,grid,origin,color,temp);
        dfs(i+1,j,grid,origin,color,temp);
        dfs(i,j-1,grid,origin,color,temp);
        dfs(i,j+1,grid,origin,color,temp);
        
        if(i-1>=0 && i+1<grid.size() && j-1>=0 && j+1<grid[0].size()){
            if(temp[i-1][j] == origin && temp[i+1][j] == origin && temp[i][j-1] == origin && temp[i][j+1] == origin){
                grid[i][j] = origin;
            }
        }
    }
    
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        
        vector<vector<int>> temp = grid;
        
        dfs(row,col,grid,grid[row][col],color,temp);
        
        return grid;
        
        
    }
};