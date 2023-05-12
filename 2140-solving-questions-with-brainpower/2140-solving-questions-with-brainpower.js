/**
 * @param {number[][]} questions
 * @return {number}
 */
var mostPoints = function(questions) {
    
    function util(index,dp){
        if(index>=questions.length) return 0;
        
        if(dp[index]!=-1) return dp[index];
        
        var take = questions[index][0] + util(index+questions[index][1]+1,dp);
        var leave = util(index+1,dp);
        
        return dp[index] = Math.max(take,leave);
    }
    
    var dp = new Array(questions.length).fill(-1);
    return util(0,dp);
};