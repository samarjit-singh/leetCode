class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i] !=')' ){
                st.push(s[i]);
            } else {
                string ss = "";
                while(!st.empty() && st.top()!='('){
                    ss+=st.top();
                    st.pop();
                }
                st.pop();
                for(int i=0;i<ss.size();i++){
                    st.push(ss[i]);
                }
            }
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};