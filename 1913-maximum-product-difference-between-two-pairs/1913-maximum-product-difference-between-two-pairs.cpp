class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        
        int a = nums[0];
        int b = nums[1];
        int c = nums[n-1];
        int d = nums[n-2];
        
        return c*d - a*b;
    }
};