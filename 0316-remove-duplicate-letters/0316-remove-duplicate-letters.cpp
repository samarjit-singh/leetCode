class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int> umap;
        unordered_map<char,bool> used;
        
        for(auto x:s){
            umap[x]++;
        }
        
        string ans = "";
        
        for(auto x:s){
            umap[x]--;
            
            if(used[x]){
                continue;
            }
            
            while(!ans.empty() && x<ans.back() && umap[ans.back()] > 0){
                used[ans.back()] = false;
                ans.pop_back();
            }
            
            ans += x;
            used[x] = true;
        }
        
        return ans;
    }
};