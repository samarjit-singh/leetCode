class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        
        int ans = 0;
        
        for(int i=s.size()-1;i>=0;i--){
            if(i!=0 && mp[s[i-1]]<mp[s[i]] ){
                 ans= ans+  mp[s[i]]-mp[s[i-1]]; 
                i--;
                continue;
            }
            ans += mp[s[i]];    
        }
        return ans;
    }
};