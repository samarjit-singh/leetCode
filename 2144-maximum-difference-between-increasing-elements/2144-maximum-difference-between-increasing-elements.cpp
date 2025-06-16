class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int min_so_far = nums[0];
        int max_diff = -1;

        for(int i=1;i<nums.size();i++) {

            if(nums[i] > min_so_far) {

                max_diff = max(max_diff, nums[i] - min_so_far);

            } else {

                min_so_far = nums[i];

            }
        }

        return max_diff;
    }
};