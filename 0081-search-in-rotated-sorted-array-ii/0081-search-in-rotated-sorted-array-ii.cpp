class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1;
        
        while( start <= end ){
            
            int mid =  start + (end - start) / 2;
            
            if(target == nums[mid]){
                return true;
            } 
            
            if((nums[start] == nums[mid]) && (nums[mid] == nums[end]))
            {
                start++;
                end--;
            } 
            else if(nums[start] <= nums[mid]){
                if((nums[start] <= target) && (nums[mid] > target)){
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
                
            } else {
                if((target > nums[mid]) && (nums[end]>= target)){
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return false;
    }
};