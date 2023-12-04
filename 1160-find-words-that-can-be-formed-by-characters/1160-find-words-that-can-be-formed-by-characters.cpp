class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int> ch;
        
        for(auto x:chars){
            ch[x]++;
        }
        
        int res = 0;
        for(auto word:words){
            unordered_map<char,int> copy = ch;
            
            for(auto x:word){
                if(copy.find(x) != copy.end() && copy[x] != 0){
                    copy[x] -= 1;
                } else {
                    res -= word.size();
                    break;
                }
            }
            res += word.size();
        }
        return res;
    }
};