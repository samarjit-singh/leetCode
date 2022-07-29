class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> ans;
        int remaining = nums.size()-k;
        
        for(auto a:nums){
            while(ans.size() && remaining && a<ans.back()) {
                ans.pop_back();
                remaining--;
            }
            ans.push_back(a);
        }
        
        while(remaining){
            ans.pop_back();
            remaining--;
        }
        
        return ans;
        
    }
};

// time and space complexity O(n)