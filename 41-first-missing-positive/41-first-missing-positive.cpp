class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
//         checking for 1
        bool contains_one = false;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 1){
                contains_one = true;
                break;
            }
        }
        
        if(!contains_one)
            return 1;
        
        
//         converting all the irrelevant numbers to 1
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] <= 0 || nums[i] > n){
                nums[i] = 1;
            }
        }
        
//         taking the value from array going to that index making that number negative
        for(int i = 0; i < n; i++){
            int x = abs(nums[i]);
            if(nums[x-1]>0)
                nums[x-1] *= -1;
        }
        
//         returning the correct number
        for(int i = 0;i < n;i++){
            if(nums[i]>0)
                return i+1;
        }
        return n+1;
    }
};