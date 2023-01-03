class Solution {
public:
    int numRabbits(vector<int>& arr) {
        unordered_map<int,int> umap;
        int ans = 0;
        for(auto x:arr){
            umap[x]++;
            if(umap[x]>x){
                ans += umap[x];
                umap.erase(x);
            }
        }
        
        for(auto it:umap){
            ans += it.first+1;
        }
        
        return ans;
        
    }
};