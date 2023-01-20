class Solution {
public:
    
    void ok(int currIndex,vector<vector<int>>& ans,vector<int>& currComb,int target,int k,int n){
        
        if(currComb.size() == k){
            if(target==0){
                ans.push_back(currComb);
                return;
            }
        }
        
        for(int i=currIndex;i<=9;i++){
            if(currComb.size()>=k && target != 0) break;
            if(i>target) break;
            currComb.push_back(i);
            ok(i+1,ans,currComb,target-i,k,n);
            currComb.pop_back();
        }
        
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> currComb;
        if(n<k){
            return ans;
        }
        ok(1,ans,currComb,n,k,n);
        return ans;
    }
};