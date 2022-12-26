class Solution {
public:
    int n,m;
    int h[4] = {0,0,-1,1}, v[4] = {-1,1,0,0};
    
    int bfs(int i,int j,vector<vector<int>> &grid){
        int count = 0;
        grid[i][j]=2;
        
        for(int k=0;k<4;k++){ // check for the surroundings if the element is valid
            int ni = i+h[k], nj=j+v[k];
            
            if(ni<0 || ni>=m || nj<0 || nj>=n || grid[ni][nj]!=1) continue;
            
            grid[ni][nj]=2;
            
            count = count+1+bfs(ni,nj,grid); //return number of time bfs is called
        }
        return count;
    }
    
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        m = grid.size(), n = grid[0].size(); // take the size of grid and each row
        vector<int> res(hits.size(),0); // make a vector for storing the result
        
        for(int i=0;i<hits.size();i++){ //run the for loop till hit size
            int x = hits[i][0], y = hits[i][1]; // the take hit location from hits
            
            if(grid[x][y]==1){ // if the ball hits the brick
                grid[x][y] = 0; // make it 0
            } else { //if the ball does not hit make it as -1,-1
                hits[i][1] = -1;
                hits[i][0] = -1;
            }
        }
        
        for(int i=0;i<n;i++){ // run the for loop for top row
            if(grid[0][i]){
                bfs(0,i,grid);
            }
        }
        
        for(int k=hits.size()-1;k>=0;k--){
            int i = hits[k][0], j = hits[k][1];
            if(i==-1 || j == -1){ // no impace was made by this ball
                res[k] = 0 ;
                continue;
            }
            grid[i][j] = 1; // initially we made the location hit with ball as 0
            if( i == 0 ){ // if its the top row
                res[k] = bfs(i,j,grid); // store in result umber of time bfs run
                continue;
            }
            for(int p=0;p<4;p++){
                int ni = i+h[p], nj=j+v[p];
//                 if the surrounding of 1 contains 2 continue
                if(ni<0 || nj<0 || ni>=m || nj>=n || grid[ni][nj]!=2) continue; 
                res[k] = bfs(i,j,grid);
                break;
            }
        }
        return res;
    
    }
};