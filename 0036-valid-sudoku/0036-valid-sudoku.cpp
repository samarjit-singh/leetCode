class Solution {
public:

    bool validate(vector<char> &board){
        unordered_map<char, int> umap;

        for(int i=0;i<board.size();i++){
            if(board[i] != '.'){
                umap[board[i]]++;
            }
        }

        for (auto x : umap){
            if(x.second>1){
                return false;
            }
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        bool res;

        // validate line
        for(int i=0;i<board.size();i++){
            if (!validate(board[i])) {
                return false;
            }
        }

        // validate column
        for(int i=0;i<board.size();i++){
            vector<char> column;

            for(int j=0; j<9 ; j++){
                column.push_back(board[j][i]);
            }

            if (!validate(column)) {
            return false;
        }
        }

        // validate grid
        for(int startRow = 0; startRow<9; startRow += 3){
            for(int startCol = 0; startCol<9; startCol += 3){
                vector<char> grid;

                for(int i=0;i<3;i++){
                    for(int j=0;j<3;j++){
                        grid.push_back(board[startRow + i][startCol + j]);
                    }
                }
                
                if (!validate(grid)) {
                    return false;
                }   

            }
        }

        return true;
    }
};