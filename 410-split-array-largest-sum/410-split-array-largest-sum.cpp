class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int start = 0;
        int end = 0;
        
        for(int i=0;i<nums.size();i++){
            start = *max_element(nums.begin(), nums.end()); //in the end it will contain the max element from the array
            end += nums[i];
        }
        
//         binary search
        while(start<end){
//             try for the middle as potential ans
            int mid = start + (end-start) / 2;
//             calculate how many piece you can divide this in with max sum
            int sum = 0;
            int pieces = 1;
            for(int num:nums){
                if(sum+num>mid){
//                     you cannot add this in this subarray , make new one
//                     say you add this num in new subarray, then sum = num
                    sum = num;
                    pieces++;                  
                } else {
                    sum += num;
                }
            }
            if(pieces>m){
                start = mid+1;
            } else {
                end = mid;
            }
        }
        
        return end; //here start == end
    }
};