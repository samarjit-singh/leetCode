class Solution {
public:
    
    void dfs(vector<vector<int>>& graph,vector<vector<int>>& ans, vector<int>& path,int curr){
        path.push_back(curr);
        if(curr == graph.size()-1){ // graph last element will be placed at the end of graph
            ans.push_back(path);
        } else {
            for(auto x : graph[curr]){ 
                dfs(graph,ans,path,x); //calling left and right elemnts of current
            }
        }
        
        path.pop_back();
        
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path;
        
        dfs(graph,ans,path,0);
        
        return ans;
    }
};