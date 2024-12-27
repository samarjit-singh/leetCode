class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int currSum = nums[0];

        for(int i=1;i<nums.size();i++){

            if(currSum <= 0){
                currSum = 0;
            }
            
            currSum += nums[i];

            maxSum = max(maxSum, currSum);


        }

        return maxSum;
    }
};