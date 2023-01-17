class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int> umap;
        
        for(auto x:nums){
            umap[x]++;
        }
        
        int n = nums.size()/2;
        int ans;
        
        for(int i=0;i<umap.size();i++){
            if(umap[nums[i]] == n){
                ans = nums[i];
                break;
            }
        }
        
        return ans;
    }
};