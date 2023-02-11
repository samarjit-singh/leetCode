class Solution {
public:
    
    unordered_map<string,bool> umap;
    bool solve(string s1,string s2){
        if(s1.size()==1) // base case
            return s1==s2;
        
        if(s1==s2) return true;
        
        string key = s1+s2;
        
        if(umap.find(key)!= umap.end())
            return umap[key];
        
        int n = s1.size();
        for(int i=1;i<s1.size();i++){
            if((solve(s1.substr(0,i),s2.substr(0,i)) and solve(s1.substr(i),s2.substr(i))) or (solve(s1.substr(0,i),s2.substr(n-i)) and solve(s1.substr(i),s2.substr(0,n-i))))
                return umap[key] = true;
        }
        return umap[key] = false;
    }
    
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        return solve(s1,s2);
    }
};