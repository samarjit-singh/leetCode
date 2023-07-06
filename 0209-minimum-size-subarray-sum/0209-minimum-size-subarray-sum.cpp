class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0;
        int j = 0;
        int sum = 0;
        int minLen = INT_MAX;
        while(j<nums.size()){
            sum += nums[j];
            while(sum>=target){
                sum -= nums[i];
                minLen = min(minLen,j-i+1);
                i++;
            }
            j++;
        }
        
        if(minLen == INT_MAX){
            return 0;
        }
        
        return minLen;
    }
};