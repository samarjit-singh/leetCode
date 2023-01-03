class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int,int> umap;
        sort(arr.begin(),arr.end());
        for(auto x:arr){
            umap[x]++;
        }
        
        for(auto x:arr){
            if(umap[x]>0 && umap[2*x]>0){
                umap[x]--;
                umap[2*x]--;
            }
        }
        
        for(auto x:umap){
            if(x.second>0)
                return false;
        }
        return true;
    }
};