class Solution {
public:

    const vector<pair<int,int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    void bfs(vector<vector<char>>& grid, int startRow,int startCol){
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int,int>> bfsQueue;

        bfsQueue.push({startRow,startCol});
        grid[startRow][startCol] = '0';

        while(!bfsQueue.empty()){
            auto [currentRow, currentCol] = bfsQueue.front();
            bfsQueue.pop();

            for(int i=0;i<4;i++){
                int neighborRow = currentRow + directions[i].first;
                int neighborCol = currentCol + directions[i].second;

                if(neighborRow >= 0 && neighborRow < rows && neighborCol>=0 
                    && neighborCol< cols && grid[neighborRow][neighborCol] == '1') {
                        grid[neighborRow][neighborCol] = '0';
                        bfsQueue.push({neighborRow,neighborCol});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()){
            return 0;
        }

        int landCount = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for(int row=0;row<rows;row++){
            for(int col=0;col<cols;col++){
                if(grid[row][col] == '1'){
                    landCount++;
                    bfs(grid,row,col);
                }
            }
        }

        return landCount;
    }
};