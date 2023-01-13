class Solution {
public:
    bool isMatch(string s, string p) {
        s=' '+s;
        p=' '+p;
        int n = s.size();
        int m = p.size();
        
        vector<vector<bool>> dp(n,vector<bool> (m,false));
        
        dp[0][0] = true;
        
        for(int i=1;i<m;i++){
            if(p[i]=='*') dp[0][i] = dp[0][i-1];
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(p[j]==s[i] || p[j]=='?') dp[i][j] = dp[i-1][j-1];
                else if(p[j]=='*') dp[i][j]=dp[i][j-1] || dp[i-1][j];
            }
        }
        
        return dp[n-1][m-1];
    }
};