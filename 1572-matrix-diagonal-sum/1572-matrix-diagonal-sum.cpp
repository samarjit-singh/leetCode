class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        
        int n = mat[0].size();
        int sum = 0;
        int countOfDiaEle = 0;
        for(int i=0;i<mat.size();i++){
            sum += mat[i][i];
            countOfDiaEle++;
        }
        
        int j=0;
        for(int i=n-1;i>=0;i--){
            sum += mat[i][j];
            j++;
        }
        
        if(countOfDiaEle%2 != 0){
            int mid1 = abs(row/2);
            int mid2 = abs(col/2);
            cout<<"Middle ele of mat "<<mat[mid1][mid2];
            sum = sum - mat[mid1][mid2];
        }
        
        return sum;
    }
};