class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size(),0);
        int left = 0;
        int right = nums.size()-1;

        for(int i=nums.size()-1; i >=0; i--){
            if(abs(nums[right]) > abs(nums[left])){
                res[i] = nums[right] * nums[right];
                right--;
            } else {
                res[i] = nums[left] * nums[left];
                left++;
            }
        }

        return res;
    }
};