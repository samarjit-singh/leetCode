class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;
        while(start<end){
            
            int mid = (start+end)/2;
            
            if((nums[start] == nums[mid]) && (nums[end] == nums[mid])){
                start++;
                end--;
                // continue;
            } else {
                if(nums[mid]>nums[end]){
                start = mid + 1;
            } else {
                end = mid;
            }
            }
            
        }
        return nums[start];
    }
};