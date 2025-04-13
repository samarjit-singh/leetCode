class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int currMin = 1, currMax = 1;

        for(int num:nums) { 
            int temp = num * currMax;

            currMax = max(max(num * currMin, num * currMax), num);
            currMin = min(min(temp, num * currMin), num);

            res = max(res, currMax);
        }

        return res;
    }
};