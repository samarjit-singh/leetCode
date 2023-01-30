class Solution {
public:
    bool isSubsequence(string s, string t) {
        // vector<string> ans;
        string ans="";
        int n = s.size();
        int m = t.size();
        
        int k =0,j=0;
        while(j<t.size()){
            if(s[k]==t[j]){
                ans += s[k];
                k++;
            }
            j++;
        }
        
    
        
        return ans==s;
    }
};