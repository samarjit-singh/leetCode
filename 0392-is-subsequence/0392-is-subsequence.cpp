class Solution {
public:
    bool isSubsequence(string s, string t) {
        string ans = "";
        int n = s.size();
        int m = t.size();
        
        int k=0,l=0;
        
        while(l<m){
            if(s[k] == t[l]){
                ans += s[k];
                k++;
            }
            l++;
        }
        
        return ans == s;
    }
};