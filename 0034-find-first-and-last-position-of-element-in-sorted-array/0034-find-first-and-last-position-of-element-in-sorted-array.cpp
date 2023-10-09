class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        
        vector<int> ans(2,-1);
        
        while(start<=end){
            int mid = (start+end)/2;
            
            if(nums[mid]<target){
                start = mid + 1;
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                if(mid == start || nums[mid]!=nums[mid-1]){
                    ans[0] = mid;
                    break;
                } else {
                    end = mid - 1;
                    ans[0] = mid-1;
                }
            }
        }    
        
        
        start = 0, end = nums.size()-1;
        while(start <= end){
            int mid = start + (end-start) / 2;
            if(nums[mid] < target)
                start = mid+1;
            else if(nums[mid] > target)
                end = mid-1;
            else {
                if(mid==end || nums[mid] != nums[mid+1] ){
                    ans[1] = mid;
                    break;
                } else {
                    start = mid+1;
                    ans[1] = mid+1;
                }
            }
        }
        
        
        return ans;
    }
};