class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        
        if(p.size()>s.size()){
            return result;
        }
        
        vector<int> pchars(26,0);
        
        for(char c:p){
            pchars[c-'a'] += 1;
        }
        
        int start = 0;
        for(int i=0;i<p.size();i++){
            pchars[s[i]-'a'] -=1;
        }
        
        bool match = true;
        for(int pc:pchars){
            if(pc!=0){
                match = false;
                break;
            }
        }
        
        if(match)
            result.push_back(start);
        
        start++;
        
        while(start <=s.size()-p.size()){
            int idx1 = s[start-1]-'a';
            int idx2 = s[start+p.size()-1]-'a';
            pchars[idx1] += 1;
            pchars[idx2] -= 1;
            
            match = true;
            for(int pc:pchars){
                if(pc!=0){
                    match = false;
                    break;
                }
            }

            if(match)
                result.push_back(start);

            start++;
        }
        
        return result;
    }
};