class Solution {
public:
    
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};
    bool util(vector<vector<int>>& cells,int row,int col,int dayAt){
        vector<vector<bool>> grid(row, vector<bool> (col,0));
        
        for(int i=0;i<dayAt;i++){ // from 0 to dayAt fill all the cells with water
            grid[cells[i][0]-1][cells[i][1]-1] = 1;
        }
        
        queue<pair<int,int>>q; // for pushing in all the top cell
        for(int c=0;c<col;c++){
            if(grid[0][c]==0){ // take all the cells from top row put them in queue
                q.push({0,c});
                grid[0][c] = 1; // and make them as water/visited
            }
        }
        
        while(!q.empty()){ // simple bfs traversal
            auto [r,c] = q.front();
            q.pop();
            if(r == row-1) return true;
            for(int i=0;i<4;i++){
                int nr = r+dx[i] , nc = c + dy[i];
                if(nr<0 || nr == row || nc < 0 || nc == col || grid[nr][nc] == 1) continue; // boundary conditions
                grid[nr][nc] = 1; // mark the cell as visited
                q.push({nr,nc});
            }
        }
        return false;
    }
    
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int left = 1, right = cells.size(), ans = 0;
        while(left<=right){ // do a simple binary search
            int mid = left + (right-left)/2; // take the mid 
            if(util(cells,row,col,mid)){ // if return true
                ans = mid; // ans becomes the max day that is mid
                left = mid + 1;
            } else {
                right = mid - 1;
            }
            
        }
        
        return ans;
    }
};