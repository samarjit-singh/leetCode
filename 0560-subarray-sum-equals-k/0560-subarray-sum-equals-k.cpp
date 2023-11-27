class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> umap;
        int ans = 0, sum = 0;
        umap[sum] = 1;
        for(auto x:nums){
            sum += x;
            int find = sum - k;
            if(umap.find(find)!=umap.end()){
                ans += umap[find];
            }
            umap[sum]++;
        }
        return ans;
    }
};