class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> umap;
        int x = 0 , y = 0;
        
        for(int i=0;i<nums.size();i++){
            x = nums[i];
            y = target-x;
            if(umap.find(y) != umap.end()){
                return {i,umap[y]};
            }
            umap[x] = i;
        }
        return {-1,-1};
    }
};