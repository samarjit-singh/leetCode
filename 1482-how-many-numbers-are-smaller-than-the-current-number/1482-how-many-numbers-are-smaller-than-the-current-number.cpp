class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> v = nums; 
        sort(v.begin(), v.end());
        vector<int> sol;

        unordered_map<int,int> umap;

        for(int i=0;i<v.size();i++){
            if(umap.find(v[i]) == umap.end()){
                umap[v[i]] = i;
            }
        }

        for(int i=0;i<v.size();i++){
            nums[i] = umap[nums[i]];
        }

        return nums;
    }
};