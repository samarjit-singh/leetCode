class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        
        queue<pair<int,int>> q,q1;
        
        int steps = 0;
        
        
//         int these two for loop if we encounter any 1
//         we will push all the 4 adjacent cell index in queue
        for(auto i=0;i<grid.size();++i){
            for(auto j=0;j<grid[i].size();++j){
                if(grid[i][j]==1)
                    q.push({i-1,j}),q.push({i+1,j}),q.push({i,j-1}),q.push({i,j+1});
            }
        }
               
//         run this loop till q is not empty
        while(!q.empty()){
            steps++; //increament the step counter
            while(!q.empty()){ //now again run this loop till q is not empty
                int i = q.front().first,j = q.front().second; //take out the index
                q.pop();
//                 check if they are valid and euqlas to 0
                if(i>=0 && i<grid.size() && j>=0 && j<grid[i].size() && grid[i][j]==0){
                    grid[i][j] = steps; //update cell value with steps so that we don't encounter it again
                    q1.push({i-1,j}),q1.push({i+1,j}),q1.push({i,j-1}),q1.push({i,j+1});
                }
                        
            }
            swap(q1,q);
        }
        
        return steps==1 ? -1:steps-1;
        
    }
};