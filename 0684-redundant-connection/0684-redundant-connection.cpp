class Solution {
public:
    
    bool dfs(vector<vector<int>>& graph,vector<bool>& vis,int cur,int par = -1){
        if(vis[cur]) return true; // node already visited - cycle exist
        
        vis[cur] = true;
        
        for(auto child : graph[cur]){
            if(child != par && dfs(graph,vis,child,cur)) return true;
        }
        
        return false;
        
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> graph(n+1); // for storing the edges of each node
        vector<bool> vis(n+1); // marking the visited nodes
        
        for(auto& E : edges){
            fill(begin(vis), end(vis),false);
             graph[E[0]].push_back(E[1]);
             graph[E[1]].push_back(E[0]);

            if(dfs(graph,vis,E[0])) // if no cycle is detected 
                return E;
            
        }
        
        return { };
        
    }
};