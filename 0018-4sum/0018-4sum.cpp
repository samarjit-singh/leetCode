class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>> store;
        long targets = target;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                
                long target_2 = targets - nums[i]-nums[j];
                
                int front = j+1;
                int back = n-1;
                
                while(front<back){
                    long two_sum = nums[front]+nums[back];
                    
                    if(two_sum<target_2) front++;
                    else if(two_sum>target_2) back--;
                    else {
                       store.insert({nums[i],nums[j],nums[front],nums[back]});
                        front++;
                        back--;
                    };   
                }
            }
        }
        
        for(auto i : store){
            res.push_back(i);  // store the answers in an array(ans)
        }
        return res;
    }
};