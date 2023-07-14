class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> dp;
        int longest = 0;
        
        for(auto num: arr){
            dp[num] = dp[num-difference] + 1;
            longest = max(longest,dp[num]);
        }
        
        return longest;
    }
};