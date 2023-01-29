class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total_sum = 0;
        int max_sumending_at = 0;
        int min_sumending_at = 0;
        int max_sum = INT_MIN;
        int min_sum = INT_MAX;
        
        for(auto x:nums){
            total_sum += x;
            max_sumending_at = max(max_sumending_at+x,x);
            max_sum = max(max_sumending_at,max_sum);
            min_sumending_at = min(min_sumending_at+x,x);
            min_sum = min(min_sumending_at,min_sum);
        }
        
        if(max_sum>0){
            return max(max_sum,total_sum-min_sum);
        }
        return max_sum;
    }
};