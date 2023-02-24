class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        
        while(l<=r){
            int mid = (l + r )/2;
            if(nums[mid] == target) return mid;
            
            if(nums[mid]>nums[r]){ // if rotation exist
                if(target<nums[mid] && target>=nums[l]) // check if its in left half or right half
                    r = mid-1;
                else 
                    l = mid+1;
            } else if(nums[mid]<nums[l]){
                if(target>nums[mid] && target<=nums[r])
                    l = mid+1;
                else 
                    r = mid-1;
            } else {
                if(target < nums[mid])
                    r = mid - 1;
                else 
                    l = mid + 1;
            }
        }
        
        return -1;
    }
};