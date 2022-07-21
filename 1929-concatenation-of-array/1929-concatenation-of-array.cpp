class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n+n,0);
        
        for(int i=0;i<n;i++){
            ans[i] = nums[i];
        }
        int sub = n;
        for(int j=n;j<n+n;j++){
            ans[j] = nums[j-sub];
        }
        return ans;
    }
};