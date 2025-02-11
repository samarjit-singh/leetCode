class Solution {
public:

    vector<pair<int,int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    void bfs(vector<vector<char>>& grid, int startRow, int startCol){
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int,int>> bfsQueue;

        grid[startRow][startCol] = '0';
        bfsQueue.push({startRow, startCol});

        while(!bfsQueue.empty()){
            auto [startRow, startCol] = bfsQueue.front();
            bfsQueue.pop();

            for(int i=0;i<4;i++){
                int nr = startRow + directions[i].first;
                int nc = startCol + directions[i].second;

                if(nr>=0 && nr<rows && nc>=0 && nc<cols && grid[nr][nc] =='1'){
                    grid[nr][nc] = '0';
                    bfsQueue.push({nr,nc});
                }
            }
        }

    }

    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int island = 0;

        for(int row=0;row<rows;row++){
            for(int col=0;col<cols;col++){
                if(grid[row][col] == '1'){
                    bfs(grid, row, col);
                    island++;
                }
            }
        }

        return island;
    }
};