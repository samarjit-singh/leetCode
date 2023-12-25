class Solution {
public:
    
    int incremovableSubarrayCount(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        
        for (int start = 0; start < n; ++start) {
            for (int end = start; end < n; ++end) {
            
                int last = -1, flag = 1;
                
                for(int k=0;k<nums.size();k++){
                    
                    if(k>=start && k<= end) continue;
                    
                    if(last >= nums[k]) {
                        flag = 0;
                        break;
                    }
                    
                    last = nums[k];
                }
                
                if(flag){
                    count++;
                }
            }
        }
        
        return count;
    }
};