class Solution {
public:
    
    void ok(vector<int>& candidates, int target,int index,vector<int> currComb,vector<vector<int>>& ans){
        
        if(target == 0){
            ans.push_back(currComb);
            return;
        }
        
        for(int i=index;i<candidates.size();i++){
            
            if(candidates[i]>target) break;
            
//             never understood the meaning of this line
            if(i  > index && candidates[i] == candidates[i-1]) continue;
            
            currComb.push_back(candidates[i]);
            ok(candidates,target-candidates[i],i+1,currComb,ans);
            currComb.pop_back();
        }
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        ok(candidates,target,0,curr,ans);
        return ans;
    }
};