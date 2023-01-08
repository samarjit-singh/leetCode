class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int,int> umap;
        for(auto it:nums){
            umap[it]++;
        }
        
        return umap.size()-umap.count(0);
    }
};