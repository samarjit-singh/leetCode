class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[s.size()] = true;

        for(int i=s.size()-1;i>=0;i--){
            for(auto w:wordDict) {
                if(i + w.size() <= s.size() && w == s.substr(i, w.size())) {
                    dp[i] = dp[w.size() + i];
                }
                if(dp[i]) {
                    break;
                }
            } 
        }

        return dp[0];
    }
};