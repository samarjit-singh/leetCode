class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size()==0) return{};
        int n = matrix.size(); // number of rows
        int m = matrix[0].size(); //number of columns
        vector<int> res;
        
        int directionFlag = 0;
        int top = 0, down = n-1, left = 0, right = m-1;
        
        while(top<=down && left<=right){
            
            if(directionFlag == 0){
                for(int i=left;i<=right;i++){
                    res.push_back(matrix[top][i]);
                }
                top++;
            } else if(directionFlag == 1){
                for(int i = top ;i <= down ; i++){
                    res.push_back(matrix[i][right]);
                }
                right--;
            } else if(directionFlag == 2){
                for(int i = right ;i >= left ; i--){
                    res.push_back(matrix[down][i]);
                }
                down--;
            } else if(directionFlag == 3){
                for(int i = down ;i >= top ; i--){
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
            directionFlag = (directionFlag+1)%4;
        }
        return res;
    }
};