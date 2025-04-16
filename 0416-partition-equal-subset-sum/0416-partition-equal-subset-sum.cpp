class Solution {
public:

    bool backtrack(vector<int>& nums, int target, int index, vector<vector<int>>& dp) {
        if(target == 0) {
            return true;
        }

        if(index == nums.size() || target< 0) {
            return false;
        }

        if(dp[index][target] != -1) {
            return dp[index][target];
        }

        bool pick = backtrack(nums, target-nums[index], index+1, dp);

        bool notPick = backtrack(nums, target, index+1, dp);

        return dp[index][target] = pick || notPick;
    }

    bool canPartition(vector<int>& nums) {
        int sumss = accumulate(nums.begin(), nums.end(), 0);
        
        if(sumss % 2 != 0) {
            return false;
        }

        vector<vector<int>> dp(nums.size(), vector<int>((sumss/2) + 1, -1));

        return backtrack(nums, sumss/2, 0, dp);
    }
};