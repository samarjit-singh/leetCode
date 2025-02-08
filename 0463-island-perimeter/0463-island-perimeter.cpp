class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(row, vector<bool>(col, false));

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j] == 1){
                    q.push({i,j});
                    visited[i][j] = true;
                    break;
                }
            }
        }

        int perimeter = 0;
        vector<pair<int,int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();

            for(auto [dr,dc] : directions){
                int nr = r + dr;
                int nc = c + dc;

                if(nr < 0 || nr >= row || nc < 0 || nc >= col || grid[nr][nc] == 0 ){
                    perimeter++;
                } else if(!visited[nr][nc]) {
                    visited[nr][nc] = true;
                    q.push({nr,nc});
                }
            }
        }

        return perimeter;
    }
};