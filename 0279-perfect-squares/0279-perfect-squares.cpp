class Solution {
public:

    int util(int n, vector<int>& perfectSquare, vector<int> &dp){

        if(n < 0){
            return INT_MAX;
        }

        if (n == 0) {
            return 0;
        }

        if (dp[n] != -1) {
            return dp[n]; 
        }

        int res = INT_MAX;

        for(int i = 0;i < perfectSquare.size(); i++){
            int subRes = util(n - perfectSquare[i], perfectSquare, dp);   
            if(subRes != INT_MAX){
                res = min(res, subRes + 1);
            }
        }

        dp[n] = res;
        return res;
    }

    int numSquares(int n) {
        vector<int> perfectSquare;
        vector<int> dp(n+1, -1);

        for(int i=1; i*i <=n; i++){
            perfectSquare.push_back(i*i);
        }

        return util(n, perfectSquare, dp);
    }
};