class Solution {
public:

    int backtrack(vector<int>& nums, int target, vector<int>& dp) {
        if(target == 0) {
            return 1;
        }

        if(target < 0) {
            return 0;
        }

        if(dp[target] != -1) {
            return dp[target];
        }

        int totalWays = 0;

        for(int i=0;i<nums.size();i++) {
            totalWays += backtrack(nums, target-nums[i], dp);
        }

        dp[target] = totalWays;

        return dp[target];
    }

    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, -1);
        int res = backtrack(nums, target, dp);

        return res;
    }
};