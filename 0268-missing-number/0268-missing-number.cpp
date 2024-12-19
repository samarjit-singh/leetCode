class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size()+1;
        int m = sizeof(nums) / sizeof(nums[0]);
        
        int sumOfI = (n * (n-1))/2;  // o(1)
        
        int sumOfArray = 0;
        for (int i=0;i<nums.size();i++){ // o(n)
            sumOfArray += nums[i];
        }
        
        return sumOfI - sumOfArray;
    }
};