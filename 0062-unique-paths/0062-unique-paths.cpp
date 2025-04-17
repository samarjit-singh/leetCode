class Solution {
public:
    int util(int m, int n, int row, int col) {
        if(row >= m || col >= n) {
            return 0;
        }
        // reached destination
        if(row == m-1 && col == n-1) {
            return 1;
        }

        int right = util(m, n, row, col+1);
        int down = util(m, n, row+1, col);

        return right+down;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m, vector<int> (n , 0));

        return util(m, n, 0, 0);
    }
};