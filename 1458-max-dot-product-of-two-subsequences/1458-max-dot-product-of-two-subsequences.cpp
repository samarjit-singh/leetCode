class Solution {
public:
    
    int dp[501][501];
    
    int returnDotProduct(vector<int>& nums1,vector<int>& nums2,int idx1, int idx2){
        if(idx1 == nums1.size() || idx2 == nums2.size()){
            return 0;
        }
        
        if(dp[idx1][idx2] != -1){
            return dp[idx1][idx2];
        }
        
        int option1 = nums1[idx1] * nums2[idx2] + returnDotProduct(nums1,nums2,idx1+1,idx2+1);
        int option2 = returnDotProduct(nums1,nums2,idx1,idx2+1);
        int option3 = returnDotProduct(nums1,nums2,idx1+1,idx2);
        
        return dp[idx1][idx2] = max({option1, option2, option3});
    }
    
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        
        // nums1_size = nums1.size();
        // nums2_size = nums2.size();

        int firstMax = INT_MIN;
        int secondMax = INT_MIN;
        int firstMin = INT_MAX;
        int secondMin = INT_MAX;

        // Calculate maximum and minimum values for nums1
        for (int num : nums1) {
            firstMax = max(firstMax, num);
            firstMin = min(firstMin, num);
        }
        // Calculate maximum and minimum values for nums2
        for (int num : nums2) {
            secondMax = max(secondMax, num);
            secondMin = min(secondMin, num);
        }

        // Check special cases where all elements are negative
        if ((firstMax < 0 && secondMin > 0) || (firstMin > 0 && secondMax < 0)) {
            return max(firstMax * secondMin, firstMin * secondMax);
        }
        
        
        memset(dp,-1,sizeof(dp));
        
        return returnDotProduct(nums1,nums2,0,0);
    }
};