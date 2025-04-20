class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> umap;
        int res = 0;
        for(auto ans:answers) {
            umap[ans]++;
            if(umap[ans]>ans){
                res += umap[ans];
                umap.erase(ans);
            }
        } 

        for(auto it:umap) {
            res += it.first + 1;
        }

        return res;
    }
};