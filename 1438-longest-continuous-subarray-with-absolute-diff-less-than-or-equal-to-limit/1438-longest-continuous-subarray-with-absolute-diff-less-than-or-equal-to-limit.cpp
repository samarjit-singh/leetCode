class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        
        deque<int> maxElement,minElement;
        
        int i=0,j;
        for(j=0;j<nums.size();j++){
            while(!maxElement.empty() && maxElement.back()<nums[j]){
                maxElement.pop_back();
            }
            
            while(!minElement.empty() && minElement.back()>nums[j]){
                minElement.pop_back();
            }
            
            maxElement.push_back(nums[j]);
            minElement.push_back(nums[j]);
            
            if(maxElement.front()-minElement.front() > limit){
                if(maxElement.front() == nums[i])
                    maxElement.pop_front();
                if(minElement.front() == nums[i])
                    minElement.pop_front();
                i++;
            }
            
        }
        return j-i;
    }
};