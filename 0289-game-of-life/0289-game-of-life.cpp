class Solution {
public:
    
//     normal function for checking validity of cell 
    bool isValidNeighbour(int x,int y, vector<vector<int>>& board){
        return (x >= 0 && x<board.size() && y >= 0 && y<board[0].size());
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        
        vector<int> dx = {0,0,1,1,1,-1,-1,-1};
        vector<int> dy = {1,-1,1,-1,0,0,1,-1};
        
        for(int row=0; row<board.size(); row++){
            for(int col = 0; col<board[0].size();col++){
                
                int countLiveNeighbours = 0;
                
                for(int i=0;i<8;i++){
                    int currX = row+dx[i], currY = col+dy[i];
                    if(isValidNeighbour(currX,currY,board) && abs(board[currX][currY]) == 1)
                        countLiveNeighbours++;
                }
                
                if(board[row][col] == 1 && (countLiveNeighbours<2 || countLiveNeighbours > 3)){
                    board[row][col] = -1; // in this case cell dies
                }
                
                
                if(board[row][col] == 0 && countLiveNeighbours==3){
                    board[row][col] = 2; // make this cell live
                }
                
                
            }
        }
        
        for(int row=0; row<board.size(); row++){
            for(int col = 0; col<board[0].size();col++){
                if(board[row][col]>=1)
                    board[row][col] = 1;
                else
                    board[row][col] = 0;
            }
        }
        
        
    }
};