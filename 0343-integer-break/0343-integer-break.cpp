class Solution {
public:

    int backtrack(int n, vector<int>& dp) {
        if(n == 1) return 1;

        if(dp[n] != -1) {
            return dp[n];
        }
        
        int maxProduct = 0;

        for(int i=1;i<n;i++) {
            int withoutBreak = i * (n-i);
            int withBreak = i * backtrack(n-i, dp);

            maxProduct = max(maxProduct, max(withoutBreak, withBreak));
        }

        return dp[n] = maxProduct;
    }

    int integerBreak(int n) {
        vector<int> dp(n+1, -1); 
        return backtrack(n, dp);
    }
};