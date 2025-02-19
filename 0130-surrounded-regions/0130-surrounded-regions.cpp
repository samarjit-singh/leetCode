class Solution {
public:

    void dfs(int r, int c, vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        if(r <= 0 || c <= 0 || r >= rows - 1 || c >= cols - 1 || board[r][c] == 'X') {
            return;
        }

        board[r][c] = 'X';

        dfs(r + 1, c, board);
        dfs(r - 1, c, board);
        dfs(r, c + 1, board);
        dfs(r, c - 1, board);

    }

    void solve(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] == 'O'){
                    dfs(i, j, board);
                }
            }
        }
    }
};