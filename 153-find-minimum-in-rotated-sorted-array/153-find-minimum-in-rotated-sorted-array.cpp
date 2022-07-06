class Solution {
public:
    int findMin(vector<int>& nums) {
//         int start = 0;
//         int end = nums.size()-1;
        
//         while(start < end){
            
//             int mid = (start + mid) / 2;
            
//             if(nums[mid]>nums[end])
//                 start = mid + 1;
//              else 
//                 end = mid;
            
//         }
//         return nums[start];
        int lo =0, hi = nums.size()-1;
        while(lo<hi){
              int mid=(lo+hi)/2;
              if(nums[mid]>nums[hi]) lo=mid+1;
              else hi=mid;
        }
        return nums[lo];
    }
};