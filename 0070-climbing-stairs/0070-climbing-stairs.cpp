class Solution {
public:
    int climbStairs(int n) {
        vector<int> ans;
        ans.push_back(0);
        for(int i=1;i<46;i++){
            if(i<4){
                ans.push_back(i);
            } else {
                ans.push_back(ans[i-1]+ans[i-2]);
            }
        }
        return ans[n];
    }
};