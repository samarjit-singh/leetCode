class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> v{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        set<string> s;
        
        for(int i=0;i<words.size();i++){
            string p = "";
            for(int j=0;j<words[i].size();j++){
                p+=v[words[i][j]-'a']; // a = 97-97 , b = 98 - 97
            }
            s.insert(p);
        }
        return s.size();
    }
};