class Solution {
public:
    
    int MOD = 1000000007;
    
    int func(int index,int count,string& corr,vector<vector<int>>& dp){
        if(corr[index] == 'S'){
            count += 1;
        }
        
        if(index == corr.size()-1){
            if(count == 2){
                return 1;
            } else {
                return 0;
            }
        }
        
        if(dp[index][count] != -1){
            return dp[index][count] % MOD;
        }
        
        if(count < 2){
            return dp[index][count] = func(index+1,count,corr,dp) % MOD;
        } else if(count == 2){
            return dp[index][count] = func(index+1,0,corr,dp) % MOD + func(index+1,count,corr,dp) % MOD;
        } else { //if count is greater than 2 this corresponds to an invalid state as more than 2 consecutive seats are not allowed.
            return dp[index][count] = 0;
        }
        
        
    }
    
    int numberOfWays(string corridor) {
        int n = corridor.size();
        vector<vector<int>> dp(n+1,vector<int>(4,-1));
        
        return func(0,0,corridor,dp) % MOD;
    }
};