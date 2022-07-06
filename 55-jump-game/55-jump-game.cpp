class Solution {
public:
    bool canJump(vector<int>& nums) {
        int minimumJump = 0;
        for(int i = nums.size()-2;i>=0;i--){
            minimumJump++;
            if(nums[i]>=minimumJump){
                minimumJump = 0;
            }
        }
        
        if(minimumJump == 0){
            return true;
        } else {
            return false;
        }
        
    }
};