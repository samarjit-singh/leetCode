class Solution {
public:
    
    int util(vector<int>& cost, vector<int>& time,int index,int timeLeft,vector<vector<int>>& dp){
        
        if(timeLeft <= 0){
            return 0;
        }
        
        if(index >= cost.size()){
            return 1e9;
        }
        
        if(dp[index][timeLeft]!=-1){
            return dp[index][timeLeft];
        } else {
            int take = cost[index] + util(cost,time,index+1,timeLeft-time[index]-1,dp);
            int nottake = util(cost,time,index+1,timeLeft,dp);
            return dp[index][timeLeft] = min(take,nottake);
        }
        
    }
    
    int paintWalls(vector<int>& cost, vector<int>& time) {
        vector<vector<int>> dp(501,vector<int>(501, -1));
        return util(cost,time,0,time.size(),dp);
    }
};