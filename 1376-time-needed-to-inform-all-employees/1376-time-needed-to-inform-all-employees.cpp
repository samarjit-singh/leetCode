class Solution {
public:
    unordered_map<int,vector<int>> umap;
    int mx = 0, ans = 0;
    
    void dfs(int manager,vector<int>& infomTime){
        mx = max(ans,mx);
        
        for(auto employee:umap[manager]){
            ans += infomTime[manager];
            dfs(employee,infomTime);
            ans -= infomTime[manager];
        }
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        for(int i=0;i<n;i++){
            int val = manager[i];
            if(val!=-1){
                umap[val].push_back(i);
            }
        }
        
        dfs(headID,informTime);
        return mx;
    }
};