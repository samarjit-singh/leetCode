class Solution {
public:
    void subsetRecur(int i, vector<int>& nums, vector<vector<int>>& res, vector<int>& subset) {
        if(i == nums.size()){
            res.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        subsetRecur(i+1, nums, res, subset);

        subset.pop_back();
        subsetRecur(i+1, nums, res, subset);
    }

    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        subsetRecur(0, nums, res, subset);

        int totalXOR = 0;

        for (auto sub:res) {
            int subXOR = 0;
            for (auto num: sub){
                subXOR ^= num;
            }
        totalXOR += subXOR;
    }
        
        return totalXOR;
    }
};