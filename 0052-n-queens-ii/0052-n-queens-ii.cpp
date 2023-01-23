class Solution {
    
    bool isSafe(int row,int col,vector<string> board,int n){
        
        int duprow = row;
        int dupcol = col;
        
//         fow top left diagonal
//         in this case row and col will always decrese
        while(row >= 0 && col >=0){
            if(board[row][col] == 'Q') return false;
            row--;
            col--;
        }
        
//         for row towards left
//         in this case row will reamin constant and column will decrese
        col = dupcol;
        row = duprow;
        while(col>=0){
            if(board[row][col] == 'Q') return false;
            col--;
        }
        
        row = duprow;
        col = dupcol;
        
        // this is for bottom left 
//         row will increae in this case and column will decrese 
        while(row<n && col>=0){
            if(board[row][col] == 'Q') return false;
            row++;
            col--;
        }
        return true;
    }
    
public:
    
    void ok(int col,vector<string>& board,vector<vector<string>> &ans,int n){
        
        if(col==n){ // this is our base case
            ans.push_back(board);
            return;
        }
        
        for(int row = 0; row < n; row++){ // iterate over each row
            if(isSafe(row,col,board,n)){ // check if it is safe to place queen at this position
                board[row][col] = 'Q'; //this is normal backtracking
                ok(col+1,board,ans,n);
                board[row][col] = '.';
            }
        }
        
    }
    
    int totalNQueens(int n) {
        vector<vector<string>> ans; // making a ans vector for stroing the ans
        vector<string> board(n); // vector for stroing the current state
        string s(n,'.'); // make a string of size n containing only '.'
        
        // for(int i=0;i<s.size();i++){
        //     cout<<s[i];
        // }
        
        for(int i=0;i<n;i++){ 
            board[i] = s; //fill the baord with '.'
        }
        
        ok(0,board,ans,n);
        
        return ans.size();
    }
};