class Solution {
public:
    
    vector<vector<int>> ans;
    
    void util(int x,vector<int>& nums,vector<int> curr){
        ans.push_back(curr);
        for(int i=x;i<nums.size();i++){
            curr.push_back(nums[i]);
            util(i+1,nums,curr);
            curr.pop_back();
        }
        return;
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        util(0,nums,curr);
        return ans;
    }
};