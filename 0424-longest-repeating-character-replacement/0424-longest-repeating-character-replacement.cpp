class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int i = 0;
        int j = 0;
        int maxC = 0; // maximum number of repeatable items
        int ans = -1;
        
        unordered_map<char,int> umap;
        
        while(j<n){
            umap[s[j]]++;
            
            maxC = max(maxC,umap[s[j]]);
            
            int currLen = j-i+1;
            if(currLen-maxC > k){
                umap[s[i]]--;
                i++;
            }
            
            currLen = j-i+1;
            ans = max(ans,currLen);
            j++;
            
        }
        return ans;
    }
};