class Solution {
public:

    bool dfs(int node, int parent, vector<vector<int>>& adjList, vector<bool>& visit){
        if(visit[node]) return true;

        visit[node] = true;

        for(int neighbour : adjList[node]){
            if(neighbour == parent) continue;
            if(dfs(neighbour, node, adjList, visit)) return true;
        }

        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adjList(n+1);

        for(auto edge:edges){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
            vector<bool> visit(n+1, false);

            if(dfs(edge[0], -1, adjList, visit)){
                return {edge[0], edge[1]};
            }
        }

        return {};
    }
};