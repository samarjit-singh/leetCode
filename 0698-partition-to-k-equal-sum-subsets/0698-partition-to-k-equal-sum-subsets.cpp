class Solution {
public:
    bool dfs(vector<int>& nums, vector<int>& subset, int index, int targetSum, int k) {
        if (index == nums.size()) {
            return true;
        }

        for (int i = 0; i < k; i++) {
            if (subset[i] + nums[index] > targetSum) continue; 

            subset[i] += nums[index];
            if (dfs(nums, subset, index + 1, targetSum, k)) return true;
            subset[i] -= nums[index]; 

            if (subset[i] == 0) break; 
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sumOfNums = accumulate(nums.begin(), nums.end(), 0);
        if (sumOfNums % k != 0) return false; 
        
        int targetSum = sumOfNums / k;
        vector<int> subset(k, 0);

        sort(nums.rbegin(), nums.rend()); 

        return dfs(nums, subset, 0, targetSum, k);
    }
};
