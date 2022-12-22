class Solution {
public:
    
    bool dfs(vector<vector<int>>& graph,vector<bool>& vis,int cur,int par = -1){
        if(vis[cur]) return true; // node already visited - cycle exist
        
        vis[cur] = true; // make current as visited
        
        for(auto child : graph[cur]){ // check in the adjacency list for each node
            
//             if child is not its parent and there exist a cycle in the graph
            if(child != par && dfs(graph,vis,child,cur) == true) return true;
        }
        
        return false; // no cycle found
        
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size(); // take the size of edges
        vector<vector<int>> graph(n+1); // for storing the edges of each node
        vector<bool> vis(n+1); // marking the visited nodes
        
        for(auto& E : edges){
            fill(begin(vis), end(vis),false); // initialize visited with false
            
//             make a adjacency list
             graph[E[0]].push_back(E[1]);
             graph[E[1]].push_back(E[0]);

            
            if(dfs(graph,vis,E[0]) == true) // if cycle is detected  return the edge
                return E;
            
        }
        
        return { };
        
    }
};