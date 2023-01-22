class Solution {
public:
    
    void ok(int currIndex,vector<vector<int>>& ans,vector<int>& currComb,int n,int k){
        if(currComb.size() == k){
            ans.push_back(currComb);
        }
        
        for(int i=currIndex;i<=n;i++){
            currComb.push_back(i);
            ok(i+1,ans,currComb,n,k);
            currComb.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> currComb;
        ok(1,ans,currComb,n,k);
        return ans;
    }
};