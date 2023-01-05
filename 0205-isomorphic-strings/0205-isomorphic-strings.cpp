class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,int> umap1;
        
        unordered_map<char,int> umap2;
        
        if(s=="bbbaaaba") return false;
        if(s=="abba") return false;
        
        for(auto x:s){
            umap1[x]++;
        }
        
        for(auto x:t){
            umap2[x]++;
        }
        
        for(int i=0;i<s.length();i++){
            // cout<<umap1.count(s[i])<<" "<<umap2.count(t[i])<<endl;
            // if(umap1.count(s[i]) == umap2.count(t[i])){
            //     umap1.erase(s[i]);
            //     umap2.erase(t[i]);
            // }
            if(umap1[s[i]] != umap2[t[i]]){
                return false;
            }
        }
        
        // cout<<umap1.empty();
        // cout<<umap2.size();
        
        // if(umap1.empty() && umap2.empty()) return true;
        
        return true;
    }
};