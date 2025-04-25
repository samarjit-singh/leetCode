class Solution {
public:
    string removeOuterParentheses(string s) {
        int opening = 0;
        int closing = 0;
        string res = "";
        int prevPointer = 0;

        for(int i=0;i<s.size();i++) {
            if(s[i] == '(') {
                opening++;
            } else if(s[i] == ')') {
                closing++;
            }

            if(opening == closing) {
                res += s.substr(prevPointer+1, i - prevPointer - 1);
                prevPointer = i + 1;
                opening = 0;
                closing = 0;
            }
        }

        return res;
    }
};