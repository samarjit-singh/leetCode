class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
//         taking size of matrix
        int n = mat.size();
        int m = mat[0].size();
        
//         making queue to store the indecies
        queue<pair<int,int>> q;
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){ // if cell contains zero 
                    q.push({i,j}); // we push it to the stack
                } else { //else we make it -1
                    mat[i][j] = -1; 
                }
                
            }
        }
        

        
//         this is for all 4 directions
        vector<vector<int>> dir{{-1,0},{1,0},{0,-1},{0,1}};
        
        while(!q.empty()){ // run the while loop till queue is empty
            
            pair<int,int>p = q.front(); //take the front element from the queue
            q.pop(); // pop it

            
            
            for(auto d:dir){
                int cell0 = p.first;
                int cell1 = p.second;
//              now check for all four directions
                int r = cell0 + d[0];
                int c = cell1 + d[1];

                if(r<0 || r>=n || c<0 || c>=m || mat[r][c]!=-1) continue;
                
                q.push({r,c});
                
                mat[r][c] = mat[cell0][cell1]+1;
                
            }
            
        }
        
        return mat;
        
    }
};

// we are using BFS appraoch in this Q