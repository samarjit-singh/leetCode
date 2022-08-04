class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        deque<pair<int,int>> dque;
        dque.push_back({0, nums[0]});
        
        for(int i=1;i<n;++i){
            int curr = nums[i] + dque.front().second;
            while(!dque.empty() && curr >= dque.back().second){
                dque.pop_back();
            }
            
            dque.push_back({i,curr});
            
            if(dque.front().first <= i-k){
                dque.pop_front();
            }
        }
        return dque.back().second;
    }
};