class Solution {
public:
    int arraySign(vector<int>& nums) {
        int ans = 1;
        for(auto x:nums){
            if(x == 0){
                ans = 0;
            } else if(x<0){
                int var = -1;
                ans *= var;
            } else {
                ans *= 1;
            }
        }
        return ans;
    }
};