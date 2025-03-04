class Solution {
public:

    void backtrack(int i,vector<int>& nums,vector<vector<int>>& res, vector<int>& subset) {
        if(i == nums.size()){
            res.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        backtrack(i+1, nums, res, subset);

        subset.pop_back();
        backtrack(i+1, nums, res, subset);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
            
        backtrack(0, nums, res, subset);

        return res;
    }
};