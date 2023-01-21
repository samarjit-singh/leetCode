class Solution {
public:
    
    void ok(int index,vector<int>& nums,vector<vector<int>>& ans){
        if(index>nums.size()){
            return;
        }
        if(index == nums.size()){
            for(int i=0;i<ans.size();i++){
                if(ans[i]==nums)
                    return;
            }
            ans.push_back(nums);
            return;
        }
        
        for(int i=index;i<nums.size();i++){
            swap(nums[index],nums[i]);
            ok(index+1,nums,ans);
            swap(nums[index],nums[i]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        ok(0,nums,ans);
        return ans;
    }
};