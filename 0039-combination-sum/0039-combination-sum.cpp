class Solution {
public:
    
    void ok(vector<int>& candidates,int target,int index,int currSum,vector<vector<int>>& ans,vector<int> currComb){
        
        if(currSum > target){
            return;
        }
        
        if(currSum == target){
            ans.push_back(currComb);
        }
        
        for(int i=index;i<candidates.size();i++){
            currComb.push_back(candidates[i]);
            currSum += candidates[i];
            ok(candidates,target,i,currSum,ans,currComb);
            currComb.pop_back();
            currSum -= candidates[i];
        }
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> currComb;
        ok(candidates,target,0,0,ans,currComb);
        return ans;
    }
};