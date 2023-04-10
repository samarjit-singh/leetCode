class Solution {
public:
    
    bool result;
    
    void solve(int i,int currentSum,int target,int k,vector<int>& num,vector<bool>&mask){
        if(k==1) {
            result = true;
            return;
        }
        
        if(i==num.size() || currentSum>target) return;
        
        if(currentSum == target) return solve(0,0,target,k-1,num,mask);
        
        if(!mask[i]){
            mask[i] = 1;
            solve(i+1,currentSum+num[i],target,k,num,mask);
            mask[i] = 0;
        }
        
        solve(i+1,currentSum,target,k,num,mask);
        
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int allSum = 0;
        
        for(int i:nums){
            allSum += i;
        }
        
        if(allSum%k!=0) return 0;
        
        vector<bool> mask(nums.size(),0);
        
        solve(0,0,allSum/k,k,nums,mask);
        
        return result;
    }
};