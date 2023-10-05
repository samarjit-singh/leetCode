class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> umap;
        vector<int> ans;
        
        for(auto x:nums){
            umap[x]++;
        }
        
        for(auto x:nums){
            if(umap[x]>nums.size()/3){
                ans.push_back(x);
                umap.erase(x);
            }
        }
        
        return ans;
    }
};