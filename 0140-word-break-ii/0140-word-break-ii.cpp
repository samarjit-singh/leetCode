class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> result;
        
        for(auto w: wordDict){
            if(s.substr(0,w.size()) == w){
                if( w.size() == s.size() )
                    result.push_back(w);
                else {
                    vector<string> temp = wordBreak(s.substr(w.size()), wordDict);
                    for(string t:temp)
                        result.push_back(w + " " + t);
                }
            }
        }
        
        return result;
    }
};