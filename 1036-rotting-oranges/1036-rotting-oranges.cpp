class Solution {
public:
    vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};

    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int,int>> bfsQueue;
        int freshcount = 0;
        int minutes = 0;

        for(int row = 0;row < rows;row++){
            for(int col = 0; col < cols; col++){
                if(grid[row][col] == 2){
                    bfsQueue.push({row,col});
                } else if (grid[row][col] == 1) {
                   freshcount++; 
                }
            }
        }

        while(!bfsQueue.empty() && freshcount > 0){
            int levelSize = bfsQueue.size();
            for(int i=0; i<levelSize;i++){
                auto [row, col] = bfsQueue.front();
                bfsQueue.pop();
                for(int i=0;i<4;i++){
                    int nr = row + directions[i].first;
                    int nc = col + directions[i].second;
                    if(nr>=0 && nr < rows && nc>=0 && nc<cols && grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        bfsQueue.push({nr,nc});
                        freshcount--;
                    }
                }   
            }
            minutes++;
        }

        return freshcount == 0 ? minutes : -1;
    }
};