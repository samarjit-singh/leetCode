class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target) return 0;
        
        unordered_map<int,vector<int>> umap;
        
        for(int i=0;i<routes.size();i++){
            for(auto x:routes[i]){
                umap[x].push_back(i);
            }
        }
        
        vector<int> visited(routes.size(),0);
        queue<int> q;
        q.push(source);
        int bus = 0;
        
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int stop = q.front();
                q.pop();
                if(stop == target) return bus;
                for(int i:umap[stop]){
                    if(visited[i]) continue;
                    visited[i] = 1;
                    for(int nextStop : routes[i]){
                        q.push(nextStop);
                    }
                }
            }
            bus++;
        }
        return -1;
    }
};