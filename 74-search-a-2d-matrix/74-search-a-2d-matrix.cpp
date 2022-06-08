class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int top = 0, down = n-1 , left = 0 , right = m-1;
        
        int found = 0;
        int directionFlag = 0;
        
        while(top<=down && left<=right){
            if(directionFlag==0){
                for(int i=left;i<=right;i++){
                    if(matrix[top][i]==target){
                        found = 1;
                    }
                }
                top++;
            } else if(directionFlag==1){
                for(int i=top;i<=down;i++){
                    if(matrix[i][right]==target){
                        found = 1;
                    }
                }
                right--;
            } if(directionFlag==2){
                for(int i=right;i>=left;i--){
                    if(matrix[down][i]==target){
                        found = 1;
                    }
                }
                down--;
            } if(directionFlag==3){
                for(int i=down;i>=top;i--){
                    if(matrix[i][left]==target){
                        found = 1;
                    }
                }
                left++;
            }
            directionFlag = (directionFlag+1)%4;
        }
        if(found==1){
            return true;
        } else {
            return false;
        }
    }
};