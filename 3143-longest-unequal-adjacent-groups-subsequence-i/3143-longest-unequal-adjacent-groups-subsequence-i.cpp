class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> res;
        int prev = -1;

        for(int i=0;i<words.size();i++) {
            if(groups[i] != prev) {
                res.push_back(words[i]);
                prev = groups[i];
            }
        }

        return res;
    }
};