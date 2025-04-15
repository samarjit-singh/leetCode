class Solution {
public:
    int maxDepth(string s) {
        int res = 0;
        int cur = 0;

        for(const auto ch: s) {
            if(ch == '(') {
                cur++;
            } else if(ch == ')') {
                cur--;
            }
            res = max(res, cur);
        }

        return res;
    }
};