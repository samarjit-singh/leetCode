class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        pq.push({nums[0],0});
        
        int ans = nums[0];
        
        for(int i=1;i<nums.size();i++){
            while(!pq.empty() && pq.top().second < i-k)
                pq.pop();
            
            nums[i] = max(nums[i],nums[i]+pq.top().first);
            pq.push({nums[i],i});
            ans = max(ans,nums[i]);
        }
        return ans;
    }
};