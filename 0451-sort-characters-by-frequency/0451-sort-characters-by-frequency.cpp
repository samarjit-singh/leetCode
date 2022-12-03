class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map<char,int> umap;
        
        for(int i=0;i<s.size();i++){
            umap[s[i]]++;
        }
        
        vector<pair<int,char>> vec;
        
        for(auto it:umap){
            vec.push_back({it.second,it.first});
        }
        
        sort(vec.begin(),vec.end());
        
        string ans="";
        for(auto it:vec)
        {
            while(it.first!=0)
            {
                // ans.push_back(it.second);//inserted according to the frequency
                ans+= it.second;
                it.first--;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};