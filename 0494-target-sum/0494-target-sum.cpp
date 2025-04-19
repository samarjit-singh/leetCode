class Solution {
public:
    int OFFSET = 1000;

    int backtrack(vector<int>& temp, vector<int>& nums, int target, int index,vector<vector<int>>& dp) {
        if(index >= nums.size()) {
            long long sumOfTemp = accumulate(temp.begin(), temp.end(), 0LL);
            if(sumOfTemp == target) {
                return 1;
            } else {
                return 0;
            }
        }
        int sumSoFar = accumulate(temp.begin(), temp.end(), 0);
        if(dp[index][sumSoFar + OFFSET] != -1) {
            return dp[index][sumSoFar + OFFSET];
        }

        temp.push_back(nums[index]);
        int plus = backtrack(temp, nums, target, index+1, dp);

        temp.pop_back();
        temp.push_back(-nums[index]);
        int minus = backtrack(temp, nums, target, index+1, dp);

        temp.pop_back();

        return dp[index][sumSoFar + OFFSET] = plus+minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        vector<int> temp;
        vector<vector<int>> dp(nums.size() + 1, vector<int>(2001, -1));
        return backtrack(temp, nums, target, 0, dp);
    }
};