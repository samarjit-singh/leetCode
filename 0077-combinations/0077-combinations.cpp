class Solution {
public:
    
    
    
    void ok(int index,int n,int k,vector<int>& curr,vector<vector<int>>& ans){
        
        if(curr.size()==k){
            ans.push_back(curr);
        }
        
        for(int i=index;i<=n;i++){
            curr.push_back(i);
            ok(i+1,n,k,curr,ans);
            curr.pop_back();
        }
        
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        vector<vector<int>> ans;
        ok(1,n,k,curr,ans);
        return ans;
    }
    

    

};