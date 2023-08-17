class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        queue<pair<int,int>> q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                } else {
                    mat[i][j] = -1;
                }
            }
        }
        
        vector<vector<int>> dir{{-1,0},{1,0},{0,-1},{0,1}};
        
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            
            for(auto d:dir){
                int cell0 = p.first;
                int cell1 = p.second;
                
                int r = cell0+d[0];
                int c = cell1+d[1];
                
                if(r<0 || r>=n || c<0 || c>=m || mat[r][c] != -1) continue;
                
                q.push({r,c});
                
                mat[r][c] = mat[cell0][cell1]+1;
            }
            
        }
        return mat;
    }
};