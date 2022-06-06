class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
               
        int dp1[n];
        int dp2[n];
        int sum = 0;
        
//         storing the maximum sum from left to right of length firstLen
        for(int i = 0; i < n; i++){
            if(i < firstLen){
                sum += nums[i];
                dp1[i] = sum;  //suppose sum here is 12 for the 2nd test case
            } else { 
                //at i = 3
                //here sum = 12 + 3 - 3 = 12
                sum += nums[i] - nums[i-firstLen]; //taking the next element and removing the previous one
                dp1[i] = max(dp1[i-1],sum); //stoing the maximum from 
            }
        }
        
        
//         similarly we will do from right to left 
//         here the max sum will be 17 for 2nd test case
        sum = 0;
        for(int i = n-1; i >= 0; i--){
            if(i+secondLen >= n){
                sum += nums[i];
                dp2[i] = sum;
            } else {
                sum += nums[i] - nums[i+secondLen];
                dp2[i] = max(dp2[i+1], sum);
            }
        }
        
        
//         here we will take the max from dp1[i] + dp2[i+1];
        int ans = 0;
        
        for(int i = firstLen-1; i < n - secondLen; i++){
            ans = max(ans, dp1[i]+dp2[i+1]);
        }
        
//         from y to x
        sum = 0;
        
        for(int i = 0; i < n; i++){
            if(i < secondLen){
                sum += nums[i];
                dp1[i] = sum;
            } else {
                sum += nums[i] - nums[i-secondLen];
                dp1[i] = max(dp1[i-1],sum);
            }
        }
        
        sum = 0;
        for(int i = n-1; i >= 0; i--){
            if(i+firstLen >= n){
                sum += nums[i];
                dp2[i] = sum;
            } else {
                sum += nums[i] - nums[i+firstLen];
                dp2[i] = max(dp2[i+1], sum);
            }
        }
        

        for(int i = secondLen-1; i < n - firstLen; i++){
            ans = max(ans, dp1[i]+dp2[i+1]);
        }
        
        
        return ans;
        
    }
};