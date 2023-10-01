class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string curr = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                curr += s[i];
            }
            else {
                reverse(curr.begin(), curr.end());
                ans += curr;
                ans += ' '; // Add a space after reversing a word
                curr = "";
            }
        }
        reverse(curr.begin(), curr.end()); // Reverse the last word
        ans += curr;
        return ans;
    }
};