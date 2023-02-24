class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        if(nums.size()==0){
            return -1;
        }
        
        int minProd = nums[0];
        int maxProd = nums[0];
        int ans = nums[0];
        
        int choice1, choice2;
        
        for(int i=1;i<nums.size();i++){
            choice1 = nums[i]*minProd;
            choice2 = nums[i]*maxProd;
            maxProd = max(nums[i],max(choice1,choice2));
            minProd = min(nums[i],min(choice1,choice2));
            
            ans = max(ans,maxProd);
        }
        
        return ans;
        
    }
};