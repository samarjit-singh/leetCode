class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int>(n,0));
        
        int totEle = n*n;
        int counter = 1;
        int direction = 0;
        int top = 0, down = n-1 , left = 0, right = n-1;
        
        while(top<=down && left<=right){
            if(direction==0){
                for(int i=left;i<=right;i++){
                    matrix[top][i] = counter;  
                    counter++;
                }
                top++;
            } else if (direction == 1){
                for(int i=top;i<=down;i++){
                    matrix[i][right]=counter;
                    counter++;
                }
                right--;
            } else if (direction == 2){
                for(int i=right;i>=left;i--){
                    matrix[down][i]=counter;
                    counter++;
                }
                down--;
            } else if (direction == 3){
                for(int i=down;i>=top;i--){
                    matrix[i][left]=counter;
                    counter++;
                }
                left++;
            }
             
            direction = (direction+1)%4;
        }
        
        return matrix;
    }
};