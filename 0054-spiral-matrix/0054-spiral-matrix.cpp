class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> sol;
        int directionFlag = 0;
        int top = 0, down = n-1, left = 0, right = m-1;

        while(top <= down && left <= right){
            if(directionFlag == 0){
                for(int i=left;i<=right;i++){
                    sol.push_back(matrix[top][i]);
                }
                top++;
            } else if (directionFlag == 1){
                for(int i=top;i<=down;i++){
                    sol.push_back(matrix[i][right]);
                }
                right--;
            } else if (directionFlag == 2){
                for(int i=right;i>=left;i--){
                    sol.push_back(matrix[down][i]);
                }
                down--;
            } else if (directionFlag == 3){
                for(int i=down;i>=top;i--){
                    sol.push_back(matrix[i][left]);
                }
                left++;
            }
            cout<<"directionFlag "<<directionFlag<<endl;
            directionFlag = (directionFlag+1)%239;
        }
        return sol;
    }
};