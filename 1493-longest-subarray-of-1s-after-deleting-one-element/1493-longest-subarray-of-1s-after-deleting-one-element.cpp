class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size(), prev = -1, curr = 0, ans = 0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                curr++;
            } else if(nums[i]==0){
                prev = curr;
                curr = 0;
            }
            ans = max(ans,prev+curr);
        }
        return ans;
    }
};