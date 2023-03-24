class Solution {
public:
    vector<vector<int>> ans;
    
    void ok(int index,vector<int>& nums){
        
        if(index == nums.size()){
            for(int i=0;i<ans.size();i++){
                if(ans[i] == nums){
                    return;
                }
            }
            ans.push_back(nums);
            return;
        }
        
        for(int i=index;i<nums.size();i++){
            swap(nums[i],nums[index]);
            ok(index+1,nums);
            swap(nums[i],nums[index]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        ok(0,nums);
        return ans;
    }
};