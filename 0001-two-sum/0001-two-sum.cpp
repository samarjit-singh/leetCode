class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> umap;

        for(int i=0;i<nums.size();i++){
            // if the complement exisit in the umap if not the add the element in umap with its index
            if(umap.find(target-nums[i]) == umap.end()){
                umap[nums[i]] = i;
            } else {
                return {umap[target-nums[i]], i};
            }
        }

        return {-1,-1};
    }
};