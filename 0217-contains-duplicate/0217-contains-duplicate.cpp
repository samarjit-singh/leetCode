class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
//         unordered_map<int,int> umap;
        
//         for(auto x: nums){
//             umap[x]++;
//         }
        
//         for(auto x:umap){
//             if(x.second>1){
//                 return true;
//             }
//         }
        
//         return true;
        
        set<int> s;
        
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        
        return s.size()<nums.size();
        
    }
};