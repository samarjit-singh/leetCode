class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int rows = mat.size(); 
        int column = mat[0].size();
        
        if(r*c != rows*column) { //if(row and col multiplication is not same, then they do not hold same amount of data)
            return mat;
        }
        
        int row = 0;
        int col = 0;
        
        vector<vector<int>> ans(r,vector<int>(c)); // making ans vector of dimension of r and c
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                
                if(col == column){
                    row++;
                    col = 0;
                }
                
                ans[i][j] = mat[row][col];
                col++;
            }
        }
        
        return ans;
        
        
    }
};