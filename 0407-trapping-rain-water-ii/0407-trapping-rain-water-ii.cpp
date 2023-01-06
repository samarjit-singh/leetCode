class Solution {
public:
    int trapRainWater(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();
        
//         made a vector for size R and initialized it with a vector of size C and initialized with 0
        vector<vector<int>>vis(R,vector<int>(C,0));
        
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        
        int vol = 0;
        
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
//                check if the current cell is the boundary cell add it to queue and mark it as visisted
                if(i==0 || i==R-1 || j==0 || j==C-1){
                    pq.push({grid[i][j],{i,j}});
                    vis[i][j] = true;
                }
            }
        }
        
        int minBdht = 0;
        
        while(!pq.empty()){
            int currHt = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            
            minBdht = max(currHt,minBdht);
            pq.pop();
            int dr[4] = {0,0,-1,1};
            int dc[4] = {1,-1,0,0};
            
            for(int i=0;i<4;i++){
                int rr = r+dr[i];
                int cc = c+dc[i]; 
                
                if(rr>=0 and rr<R and cc>=0 and cc<C and vis[rr][cc]==false){
                    pq.push({grid[rr][cc],{rr,cc}});
                    vis[rr][cc] = true;
                    if(grid[rr][cc]<minBdht){
                        vol += minBdht - grid[rr][cc];
                    }
                }
                
            }
            
        }
        
        return vol;
    }
};