class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> ans(m);
        
        for(int ball = 0; ball < m; ball++){
            int i = 0, j = ball , flag = 0;
            while(i < n){
                if(grid[i][j]==1){
                    if(j == m-1 || grid[i][j+1] == -1 ){
                        flag = 1;
                        break;
                    }
                    i++; 
                    j++;
                } else {
                    if(j == 0 || grid[i][j-1] == 1){
                        flag = 1;
                        break;
                    }
                    i++;
                    j--;
                }
            }
            if(flag){
                ans[ball] = -1;
            } else {
                ans[ball] = j;
            }
        }
        return ans;
    }
};