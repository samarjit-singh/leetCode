class Solution {
public:
    
    void dfs(unordered_map<int,vector<int>>& mp,int cur,set<int>& visited,vector<int>& ans){
        if(visited.find(cur) != visited.end()){
            return;
        }
        visited.insert(cur);
        ans.push_back(cur);
        for(auto x:mp[cur]){
            dfs(mp,x,visited,ans);
        }
    }
    
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,vector<int>> mp;
        
        for(auto x:adjacentPairs){
            mp[x[0]].push_back(x[1]);
            mp[x[1]].push_back(x[0]);
        }
        
        int head = 0;
        for(auto x:mp){
            if(x.second.size() == 1){
                head = x.first;
                break;
            }
        }
        
        set<int> visited;
        vector<int> ans;
        dfs(mp,head,visited,ans);
        return ans;
        
    }
};