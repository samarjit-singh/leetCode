class Solution {
public:
    
    long long util(vector<vector<int>>& questions, int index,vector<long>& dp){
        
        if(index>=questions.size()) return 0;
        
        if(dp[index]!=-1) return dp[index];
        
        long long take = questions[index][0] + util(questions,index+questions[index][1]+1,dp);
        long long leave = util(questions,index+1,dp);
        
        return dp[index] = max(take,leave);
        
    }
    
    long long mostPoints(vector<vector<int>>& questions) {
       
        vector<long> dp(questions.size(),-1);
        return util(questions,0,dp);
        
    }
};