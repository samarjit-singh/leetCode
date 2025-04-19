class Solution {
public:

    int backtrack(int sum, vector<int>& nums, int target, int index) {
        if(index == nums.size()) {
            return sum == target ? 1 : 0;
        }

        int plus = backtrack(sum + nums[index], nums, target, index+1);

        int minus = backtrack(sum - nums[index], nums, target, index+1);

        return plus+minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return backtrack(0, nums, target, 0);
    }
};