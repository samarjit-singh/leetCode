class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int r = dungeon.size();
        int c = dungeon[0].size();
        
        vector<vector<int>> sol(r,vector<int>(c));
        
//         if bottom right ele is > 0 put 1 else one elemnt greater than than the elemnet present
        sol[r-1][c-1] = dungeon[r-1][c-1] > 0 ? 1 : 1 - dungeon[r-1][c-1];
        
//         update the last column so column is fixed
        for(int i=r-2;i>=0;i--)
            sol[i][c-1] = max(sol[i+1][c-1]-dungeon[i][c-1],1);
            
//         similarly solve for last row
            
        for(int j=c-2;j>=0;j--)
            sol[r-1][j] = max(sol[r-1][j+1]-dungeon[r-1][j],1);
        
        
        for(int i=r-2;i>=0;i--)
            for(int j=c-2;j>=0;j--)
                sol[i][j] = max(min(sol[i+1][j],sol[i][j+1])-dungeon[i][j],1);
        
        return sol[0][0];
            
    }
};