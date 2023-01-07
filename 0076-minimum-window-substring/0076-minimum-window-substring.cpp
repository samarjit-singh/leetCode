class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<int,int> hash_s;
        unordered_map<int,int> hash_t;
        
        int len_s = s.size();
        int len_t = t.size();
        
        if(len_s<len_t)
            return "";
        
        for(int i=0;i<len_t;i++){
            hash_t[t[i]]++;
        }
        
        int count = 0, start = 0, min_len = INT_MAX, start_ind = -1;
        
        for(int j=0;j<len_s;j++){
            
            hash_s[s[j]]++;
            
//             if characer matches in the string
            if(hash_s[s[j]] <= hash_t[s[j]]){
                count++;
            }
            
            if(count==len_t){
                while(hash_s[s[start]] > hash_t[s[start]] || hash_t[s[start]] == 0){
                    if(hash_s[s[start]]>hash_t[s[start]]){
                        hash_s[s[start]]--;
                        start++;
                    }
                }
                if(min_len>j-start+1){
                    min_len = j-start+1;
                    start_ind = start;
                }
            }
            
        }
        if(start_ind==-1){
            return "";
        }
        
        return s.substr(start_ind,min_len);
    }
};