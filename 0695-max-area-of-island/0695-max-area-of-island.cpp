class Solution {
public:

    vector<pair<int,int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    int bfs(vector<vector<int>>& grid, int startRow, int startCol) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int,int>> bfsQueue;
        bfsQueue.push({startRow,startCol});

        int count = 1;
        grid[startRow][startCol] = 0;

        while(!bfsQueue.empty()){
            auto [row, col] = bfsQueue.front();
            bfsQueue.pop();

            for(int i=0;i<4;i++){
                int nr = row + directions[i].first;
                int nc = col + directions[i].second;

                if(nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1){
                    count += 1;
                    grid[nr][nc] = 0;
                    bfsQueue.push({nr,nc});
                }
            }

        }

        return count;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int area = 0;

        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                if(grid[row][col] == 1){
                    int a = bfs(grid, row, col);
                    area = max(area, a);
                }
            }
        }

        return area;
    }
};