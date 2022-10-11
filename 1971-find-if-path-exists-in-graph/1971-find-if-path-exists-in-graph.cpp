class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>> umap; // make a unorder map to store the friends of each vertex
        
        for(auto x:edges){ // now itereste over the edges
            vector<int> temp = x; // take that x store it in a temp vector
             
            int u = temp[0]; // take the first element from temp vector store it in u
            int v = temp[1]; // take the second element from temp vector store it in v
            
            
//             so in umap for each int we are storing a vector thats why we are doing push back
            umap[u].push_back(v); 
            umap[v].push_back(u);
        }
        
        
        vector<bool>visited(n,false); // make a vector visisted of size of edges and initialize it with false
        
        queue<int> q; // make a quue
        q.push(source); //push the sourse into it
        visited[source] = true; // and make the first edge as visisted
        
        while(!q.empty()){ // run the while loop till the queue is empty
            int v = q.front();
            q.pop();
            
            vector<int> temp = umap[v];
            for(int i=0;i<temp.size();i++){
                int vertex = temp[i];
                if(visited[vertex]==false){
                    q.push(vertex);
                    visited[vertex] = true;
                }
            }
        }
        
        return visited[destination];
    }
};
// in this logic from source all the edges connected will be marked as visited