class Solution {
public:

    void backtrack(int start, int end, vector<int>& nums, vector<vector<int>>& res) {
        if(start == end){
            res.push_back(nums);
            return;
        }

        for(int i=start;i<end;i++){
            swap(nums[i], nums[start]);
            backtrack(start+1, nums.size(), nums,res);
            swap(nums[i], nums[start]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;

        backtrack(0, nums.size(), nums,res);

        return res;
    }
};