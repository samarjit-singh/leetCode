class Solution {
    int countPalindrome(string s,int l,int r){
        int count=0;
        while(l>=0 && r<s.size() && s[l]==s[r]){
            l--;
            r++;
            count++;
        }
        return count;
    }
public:
    int countSubstrings(string s) {
        int count = 0;
        for(int i=0;i<s.size();i++){
            count += countPalindrome(s,i,i) + countPalindrome(s,i,i+1);
        }
        return count;
    }
};