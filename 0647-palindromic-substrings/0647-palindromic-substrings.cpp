class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int a[n][n];
        int ans = n;
        
        memset(a,0,sizeof(a));
        
        for(int i=0;i<n;i++) a[i][i] = 1;
        
        for(int i = 1;i<n;i++){
            if(s[i]==s[i-1]) a[i-1][i] = 1, ans++;
        }
        
        for(int len=3;len<=n;len++){
            for(int j=0;j<n-len+1;j++){
                if(s[j] == s[len+j-1] && a[j+1][j+len-2]==1) a[j][j+len-1]=1,ans++;
            }
        }
        return ans;
    }
};