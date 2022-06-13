class Solution {
public:
    string longestPalindrome(string s) {  
        int max_len = 1;
        int n = s.size();
        int start = 0, end = 0;
        
        //odd length
        for(int i=0;i<n-1;i++){
            int l = i-1, r = i+1;
            while(l>=0 && r<n){
                if(s[l] == s[r]){
                    l--;
                    r++;
                } else {
                    break;
                }
            }
            int len = r-l-1;
            if(len>max_len){
                max_len = len;
                start = l+1;
                end = r-1;
            }
        }
        
        //even length
        for(int i=0;i<n-1;i++){
            int l = i, r = i+1;
            while(l>=0 && r<n){
                if(s[l] == s[r]){
                    l--;
                    r++;
                } else {
                    break;
                }
            }
            int len = r-l-1;
            if(len>max_len){
                max_len = len;
                start = l+1;
                end = r-1;
            }
        }
        
        return s.substr(start,max_len);
    }
};