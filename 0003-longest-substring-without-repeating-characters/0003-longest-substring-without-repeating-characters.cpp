class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0;
        int n = s.size();
        
        set<char> st;
        int ans = 0;
        
        while(i<n && j<n){
            if(st.count(s[j]) == 0){
                st.insert(s[j]);
                j++;
                ans = max(ans,j-i);
            } else {
                st.erase(s[i]);
                i++;
            }
        }
        return ans;
    }
};