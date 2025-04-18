class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size()+1;
        int n = text2.size()+1;
        int maxCount = 0;

        vector<vector<int>> dp(n, vector<int> (m, 0));

        for(int j=0; j<n-1;j++) {
            for(int i=0;i<m-1;i++) {
                if(text1[i] == text2[j]) {
                    dp[j+1][i+1] = 1;
                }
            }
        }

        for(int i=1;i<dp.size();i++) {
            for(int j=1;j<dp[0].size();j++) {
                if(dp[i][j] == 1) {
                    dp[i][j] = 1+dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }


        return dp[n-1][m-1];
    }
};