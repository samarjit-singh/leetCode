class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)
            return 0;
        
        // int dp[len][len];
        vector<vector<int>> dp(len, vector<int>(len));
        
        for(int n=0;n<len;n++){
            for(int i=0;i+n<len;i++){
                int j = i+n;
                for(int k=i;k<=j;k++){ //traversing the sub aray which starts at i nad ends at j
                    int leftNum = i==0?1:nums[i-1];
                    int rightNum = j==len-1?1:nums[j+1];
                    
                    int left = k==i?0:dp[i][k-1];
                    int right = k==j?0:dp[k+1][j];
                    
                    dp[i][j] = max(dp[i][j], leftNum*nums[k]*rightNum + left + right);
                }
            }
        }
        
        return dp[0][len-1];
    }
};