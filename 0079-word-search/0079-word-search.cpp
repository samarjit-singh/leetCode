class Solution {
public:
    vector<pair<int, int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    bool dfs(vector<vector<char>>& board, string word, int index, int row, int col){
        if(index == word.size()){
            return true;
        }

        if(row<0 || row>=board.size() || col<0 || col>=board[0].size() || board[row][col]!=word[index]){
            return false;
        }

        char temp = board[row][col];
        board[row][col] = '#';

        for(auto [dr,dc]:directions){
            if(dfs(board,word, index+1, row+dr, col+dc)){
                return true;
            }
        }

        board[row][col] = temp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(dfs(board, word, 0, i, j)){
                    return true;
                }
            }
        }


        return false;
    }
};