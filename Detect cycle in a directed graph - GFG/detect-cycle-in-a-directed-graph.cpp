//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    
    bool cycle(int s,vector<bool>&visited,vector<bool>&currVisited,vector<int> adj[]){
        visited[s] = true;
        currVisited[s] = true;
        
        for(auto x: adj[s]){
            if(visited[x]==false){
                if(cycle(x,visited,currVisited,adj)){
                    return true;
                }
                
            } else if(visited[x]==true && currVisited[x]==true){
                return true;
            }
        }
        
        currVisited[s] = false;
        
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> visited(V,false), currVisited(V,false);
        for(int i=0;i<V;i++){
            if(visited[i]==false){
                if(cycle(i,visited,currVisited,adj))
                    return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends