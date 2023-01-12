class Solution {
public:
    bool canConstruct(string s, int k) {
        
        vector<int> a(26);
        
        for(int i=0;i<s.size();i++){
            a[s[i]-'a']++;
        }
        
        int odd = 0;
        int even = 0;
        for(int i=0;i<26;i++){
            if(a[i]%2 != 0){
                odd++;
            } else {
                even++;
            }
        }
        
        if(odd>k)
            return false;
        
        if(even==k)
            return true;
        
        if(s.size()<k)
            return false;
        
        return true;
    }
};