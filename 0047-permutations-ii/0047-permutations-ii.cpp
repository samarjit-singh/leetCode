class Solution {
public:

    void util(int start, vector<int>& nums, vector<vector<int>>& res) {

        if(start == nums.size()){
            for(int i=0;i<res.size();i++){
                if(res[i] == nums){
                    return;
                }
            }
            res.push_back(nums);
            return;
        }


        for(int i=start; i<nums.size();i++){
            swap(nums[i], nums[start]);
            util(start+1, nums, res);
            swap(nums[i], nums[start]);
        }

    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;

        util(0, nums, res);

        return res;
    }
};