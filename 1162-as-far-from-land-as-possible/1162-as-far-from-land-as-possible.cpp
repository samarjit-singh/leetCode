class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        
        queue<pair<int,int>> q,q1;
        
        int steps = 0;
        
        for(auto i=0;i<grid.size();++i){
            for(auto j=0;j<grid[i].size();++j){
                if(grid[i][j]==1)
                    q.push({i-1,j}),q.push({i+1,j}),q.push({i,j-1}),q.push({i,j+1});
            }
        }
                
                while(!q.empty()){
                    ++steps;
                    while(!q.empty()){
                        int i = q.front().first,j = q.front().second;
                        q.pop();
                        if(i>=0 && i<grid.size() && j>=0 && j<grid[i].size() && grid[i][j]==0){
                            grid[i][j] = steps;
                            q1.push({i-1,j}),q1.push({i+1,j}),q1.push({i,j-1}),q1.push({i,j+1});
                        }
                        
                    }
                    swap(q1,q);
                }
        
        
        return steps==1 ? -1:steps-1;
        
    }
};