class Solution {
public:
    
    int lcsUtil(int n,int m,string &a,string &b,int dp[][1001]){
        if(m==0 || n==0) return 0;
        
        if(dp[n][m]!=-1)
            return dp[n][m];
        
        if(a[n-1] == b[m-1])
             dp[n][m] = 1+lcsUtil(n-1,m-1,a,b,dp);
        else
             dp[n][m] = max(lcsUtil(n,m-1,a,b,dp),lcsUtil(n-1,m,a,b,dp));
        
        return dp[n][m];
    }
    
    
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        
        // vector<vector<int>> dp(1001,vector<int>(1001,-1));
        int dp[1001][1001];
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                dp[i][j] = -1;
            }
        }
        
        return lcsUtil(n,m,text1,text2,dp);
    }
};