class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> ans;
        map<string,vector<string>> hm;
        
        for(auto word:strs){
            string sorted = word;
            sort(sorted.begin(),sorted.end());
            hm[sorted].push_back(word);
        }
        
        for(auto &it:hm){
            ans.push_back(it.second);
        }
        return ans;
    }
};