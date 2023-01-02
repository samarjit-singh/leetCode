class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        if(deck.size()==1) return false;
        unordered_map<int,int> umap;
        for(int i=0;i<deck.size();i++){
            umap[deck[i]]++;
        }
        
//         for(auto x:umap){
//             cout<<x.first<<" "<<x.second<<endl;
//         }
        
//         set<int> s;
//         for(auto x:umap){
//             s.insert(x.second);
//         }
        
//         cout<<s.size();
        
//         if(s.size()==1)
//             return true;
        int f = 0;
        for(auto it:umap){
            f = __gcd(f,it.second);
        }
        
        return f>=2;
    }
};