class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> nums_set(nums.begin(),nums.end());
        
        int res = 0;
        for(int n:nums){
            if(nums_set.find(n) != nums_set.end()){
                nums_set.erase(n);
                int prev = n-1;
                int next = n+1;
                while(nums_set.find(prev) != nums_set.end()) nums_set.erase(prev--);
                while(nums_set.find(next) != nums_set.end()) nums_set.erase(next++);
                res = max(res,next-prev-1);
            }
        }
        return res;
    }
};