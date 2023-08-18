class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int ans = 0;
        
        vector<unordered_set<int>> adj(n,unordered_set<int>());
        
        for(auto road:roads){
            adj[road[0]].insert(road[1]);
            adj[road[1]].insert(road[0]);
        }
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int temp = adj[i].size() + adj[j].size();
                
                if(adj[i].count(j))
                    temp--;
                
                ans = max(ans,temp);
            }
        }
        return ans;
    }
};