class Solution {
public:
    
    bool getAns(vector<int>& nums,int threshold, int divisor){
        int n = nums.size();
        int sum = 0;
            
        for(int i=0;i<n;i++){
            sum += (nums[i]+divisor-1)/divisor;
        }
        
        if(sum>threshold)
            return false;
        else 
            return true;
        
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int start = 1, end = *max_element(nums.begin(),nums.end()), ans=0;
        while(start < end){
            int mid = (start + end)/2;
            if(getAns(nums,threshold,mid)){
                end = mid;
            } else {
                ans = mid;
                start = mid+1;
            }
        }
        return ans+1;
    }
};