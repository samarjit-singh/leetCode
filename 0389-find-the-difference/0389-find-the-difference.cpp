class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> umap;
        
        for(auto x:s){
            umap[x]++;
        }
        
        for(auto x:t){
            if(umap.find(x) == umap.end()){
                return x;
            }
            
            if(umap[x]>1){
                umap[x]--;
            } else {
                umap.erase(x);
            }
        }
        
        return 'a';
    }
};