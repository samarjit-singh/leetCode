class Solution {
public:

    void dfs(int r, int c, vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        if (r < 0 || c < 0 || r >= rows || c >= cols || board[r][c] != 'O') {
            return;
        }

        board[r][c] = '#';

        dfs(r + 1, c, board);
        dfs(r - 1, c, board);
        dfs(r, c + 1, board);
        dfs(r, c - 1, board);

    }

    void solve(vector<vector<char>>& board) {

        int rows = board.size();
        int cols = board[0].size();

        for (int i = 0; i < rows; i++) {
            if (board[i][0] == 'O') dfs(i, 0, board);       // Left column
            if (board[i][cols - 1] == 'O') dfs(i, cols - 1, board); // Right column
        }
        for (int j = 0; j < cols; j++) {
            if (board[0][j] == 'O') dfs(0, j, board);       // Top row
            if (board[rows - 1][j] == 'O') dfs(rows - 1, j, board); // Bottom row
        }

        // Step 2: Convert remaining 'O' to 'X'
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }

        // Step 3: Restore marked '#' cells back to 'O'
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};