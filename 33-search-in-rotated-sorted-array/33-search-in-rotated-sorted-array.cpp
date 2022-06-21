class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1;
        while(start<=end){
            int mid = (start+end)/2;
            if(target==nums[mid])
                return mid;
            
            if(nums[mid]>nums[end]){ //if rotation exist
                if(target < nums[mid] && target >= nums[start]) //middle elemnt is in left of array
                    end = mid - 1;
                else 
                    start = mid + 1;
            } else if(nums[mid] < nums[start]){ //if rotation exist
                if(target > nums[mid] && target <= nums[end]) //middle elemnt is in right of array
                    start = mid + 1;
                else
                    end = mid - 1;
            } else {
                if(target < nums[mid])
                    end = mid - 1;
                else 
                    start = mid + 1;
            }
            
        }
        return -1;
    }
};