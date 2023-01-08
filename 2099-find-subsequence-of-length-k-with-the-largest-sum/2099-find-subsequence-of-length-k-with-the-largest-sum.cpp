class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> ans;
        vector<int> temp = nums;
        unordered_map<int,int> umap;
        
        sort(nums.begin(),nums.end(),greater<int>());
        
        for(int i=0;i<k;i++)
            umap[nums[i]]++;
        
        for(auto it:temp){
            if(umap[it]-- > 0)
                ans.push_back(it);
        }
        
        return ans;
        
    }
};