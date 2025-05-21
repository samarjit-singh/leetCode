class Solution {
public:
    
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<pair<int,int>> coordinates;

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(matrix[i][j] == 0) {
                    coordinates.push_back({i,j});
                }
            }
        }

        for(auto coord:coordinates) {
            int row = coord.first;
            int col = coord.second;

            for(int j=0;j<m;j++) {
                matrix[row][j] = 0;
            }

            for(int i=0;i<n;i++) {
                matrix[i][col] = 0;
            }
        }
    }
};