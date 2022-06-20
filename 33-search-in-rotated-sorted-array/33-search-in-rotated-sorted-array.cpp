class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;
        int flag = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                ans = i;
                flag = 1;
                break;
            } 
        }
        if(flag == 0){
            ans = -1;
        }
        return ans;
    }
};