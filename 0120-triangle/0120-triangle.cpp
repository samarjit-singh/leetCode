class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> ans(n,vector<int>(n,0));
        ans[0][0] = triangle[0][0];
        for(int i=1;i<n;i++){ // for traversing in rows
            for(int j=0;j<(int)triangle[i].size();j++){ // for traversing in columns
                if(j==0) ans[i][j] = ans[i-1][j] + triangle[i][j];
                else if(j==(int)triangle[i].size() - 1) ans[i][j] = ans[i-1][j-1] + triangle[i][j];
                else ans[i][j] = min(ans[i-1][j],ans[i-1][j-1]) + triangle[i][j];
            }
        }
        int sol = INT_MAX;
        for(int i=0;i<n;i++) sol = min(sol,ans[n-1][i]);
        
        return sol;
    }
};