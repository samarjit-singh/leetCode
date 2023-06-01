class Solution {
public:
    
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        if(grid[0][0] == 1 || grid[n-1][m-1]==1){
            return -1;
        }
        
        if(n==1 && m==1 && grid[n-1][m-1]==0) return 1;
        
        // if(grid[0][0]==0 && grid.size() == 1 && grid[0].size() == 1) return 1;
        
        
        
        queue<pair<pair<int,int>,int>>q;
        q.push({{0,0},1});
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        
        while(!q.empty()){
            pair<int,int> p = q.front().first;
            int x = p.first;
            int y = p.second;
            int lengthOfPath = q.front().second;
            q.pop();
            
            vector<pair<int,int>> negighbours{{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1}};
            
            for(pair<int,int>negighbour : negighbours){
                int newx = negighbour.first+x;
                int newy = negighbour.second+y;
                
                if(newx>=0 && newy>=0 && newx<n && newy<m && grid[newx][newy]==0 && !visited[newx][newy]){
                    q.push({{newx,newy},lengthOfPath+1});
                    visited[newx][newy] = true;
                }
                
                if(newx==n-1 && newy == m-1){
                    return lengthOfPath+1;
                }
            }
            
        }
        
        return -1;
    }
};