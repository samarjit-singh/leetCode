class Solution {
public:
    
    void ok(vector<int>& candidates,int target,int currIndex,vector<vector<int>>& ans,vector<int>& currComb){
        // if(currSum>target)
        //     return;
        
        if(target==0){
            ans.push_back(currComb);
            return;
        }
        
        for(int i=currIndex;i<candidates.size();i++){
            if(candidates[i] > target) break;
      
            
            if(i  > currIndex && candidates[i] == candidates[i-1])
                continue;
            
            currComb.push_back(candidates[i]);
            ok(candidates,target-candidates[i],i+1,ans,currComb);
            currComb.pop_back();
            // currSum -=  candidates[i];
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> currComb;
        sort(candidates.begin(),candidates.end());
        ok(candidates,target,0,ans,currComb);
        return ans;
     }
};