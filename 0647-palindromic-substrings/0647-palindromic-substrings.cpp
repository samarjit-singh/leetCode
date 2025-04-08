class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;

        for(int i=0;i<s.length();i++){
            int left = i;
            int right = i;
            while(left >=0 && right < s.length() && s[left] == s[right]){
                res += 1;
                left -= 1;
                right += 1;
            }

            int l = i;
            int r = i+1;
            while(l >=0 && r < s.length() && s[l] == s[r]){
                res += 1;
                l -= 1;
                r += 1;
            }
        }
        
        
        return res;
    }
};