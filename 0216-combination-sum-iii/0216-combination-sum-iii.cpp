class Solution {
public:
    
    void ok(int k,int n,int index,vector<vector<int>>& ans,vector<int>& currComb,int target){
        
        if(currComb.size() == k){
            if(target == 0){
                ans.push_back(currComb);
                return;
            }
        }
        
        for(int i=index;i<=9;i++){
            
            // if(currComb.size() >=k && target!=0) break;
            // if(i>target) break;
            
            currComb.push_back(i);
            ok(k,n,i+1,ans,currComb,target-i);
            currComb.pop_back();
        }
        
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> currComb;
        ok(k,n,1,ans,currComb,n);
        return ans;
    }
};