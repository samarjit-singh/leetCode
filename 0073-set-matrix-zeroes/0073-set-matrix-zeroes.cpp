class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int col0 = 1;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == 0){
                    // mark the cell in 1st row
                    matrix[i][0] = 0;
                    if(j != 0) { // j is not the first cell
                        matrix[0][j] = 0; // mark the cell in first column
                    } else {
                        // add a new cell in first colum and mark it
                        col0 = 0;
                    }
                }
            }
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]!=0){
                    if(matrix[0][j] == 0 || matrix[i][0] == 0){
                        matrix[i][j] = 0;
                    }
                }
            }
        }
        
        if(matrix[0][0] == 0){
            for(int j=0;j<m;j++) matrix[0][j] = 0;
        }
        
        if(col0 == 0){
            for(int i=0;i<n;i++){
                matrix[i][0] = 0;
            }
        }
        
    }
};