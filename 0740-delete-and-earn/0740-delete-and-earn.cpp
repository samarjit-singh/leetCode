class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxi = *max_element(nums.begin(),nums.end());
        int dp[20005];
        vector<int>freq(20005);
        
        for(auto i:nums) freq[i]++;
        
        dp[1] = freq[1];
        dp[2] = max(freq[1],freq[2]*2); // either take 2 or not take 2
        for(int i=2;i<=maxi;i++){
            dp[i] = max(dp[i-1],dp[i-2]+freq[i]*i);
        }
        
        return dp[maxi];
    }
};