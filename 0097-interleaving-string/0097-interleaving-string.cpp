class Solution {
public:
    bool dp(string& s1, string& s2, string& s3, int i, int j, vector<vector<int>>& memo) {
        if(i + j == s3.size()) {
            return true;
        }

        if(memo[i][j] != -1) return memo[i][j];

        bool matchS1 = false, matchS2 = false;

        if(i < s1.size() && s1[i] == s3[i + j]) {
            matchS1 = dp(s1, s2, s3, i + 1, j, memo);
        }

        if(j < s2.size() && s2[j] == s3[i + j]) {
            matchS2 = dp(s1, s2, s3, i, j + 1, memo);
        }

        return memo[i][j] = matchS1 || matchS2;
    }

    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) return false;

        vector<vector<int>> memo(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        return dp(s1, s2, s3, 0, 0, memo);
    }
};
