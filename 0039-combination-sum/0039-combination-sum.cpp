class Solution {
public:
    
    void ok(vector<int>& candidates, int target, vector<int> currComb, int currSum, int currIndex, vector<vector<int>>& ans){
        if(currSum>target)
            return;
        
        if(currSum == target){
            ans.push_back(currComb);
            return;
        }
        
        for(int i=currIndex;i<candidates.size();i++){
            currComb.push_back(candidates[i]);
            currSum += candidates[i];
            ok(candidates,target,currComb,currSum,i,ans);
            currComb.pop_back();
            currSum -= candidates[i];
        }
        return;
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> currComb;
        ok(candidates,target,currComb,0,0,ans);
        
        return ans;
    }
};