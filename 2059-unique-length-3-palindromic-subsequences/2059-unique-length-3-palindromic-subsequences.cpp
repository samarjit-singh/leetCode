class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> right(26);
        vector<int> left(26);

        unordered_set<string> uset;

        for(auto x:s){
            right[x-'a']++;
        }

        for(int i=0;i<s.size();i++) {
            right[s[i]-'a']--;
            for(int j=0;j<26;j++) {
                if(left[j] > 0 && right[j] > 0) {
                    char x = 'a' + j;

                    string palindrome = "";
                    palindrome += x;
                    palindrome += s[i];
                    palindrome += x;

                    if(uset.count(palindrome) == true) continue;

                    uset.insert(palindrome);
                }
            }
            left[s[i]-'a']++;
        }

        return uset.size();
    }
};