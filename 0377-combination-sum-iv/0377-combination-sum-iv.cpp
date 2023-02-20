class Solution {
public:
    
    vector<int> dp;
    int solve(vector<int>& nums,int target){
        
        if(target == 0) return 1;
        
        if(target < 0) return 0;
        
        if(dp[target] != -1)
            return dp[target];
        
        int ways = 0;
        
        for(auto i:nums)
            ways += solve(nums,target-i);
        
        return dp[target] = ways;
        
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        
        dp.resize(target+1,-1);
        return solve(nums,target);
    }
};