class Solution {
public:
    int bfs(int start, vector<vector<int>>& adj, int k) {
        queue<pair<int, int>> q;
        q.push(make_pair(start, -1));
        int count = 0;

        while(!q.empty() && k>=0) {
            int size = q.size();
            count += size;

            for(int i=0;i<size;i++) {
                auto curr = q.front();
                q.pop();

                int u = curr.first;
                int parent = curr.second;
                for(int v:adj[u]) {
                    if(v!=parent) {
                        q.push(make_pair(v,u));
                    }
                }
            }
            k--;
        }

        return count;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int m = edges1.size() + 1;
        int n = edges2.size() + 1;

        vector<vector<int>> adj1(m), adj2(n);

        for(auto& edge:edges1){
            adj1[edge[0]].push_back(edge[1]);
            adj1[edge[1]].push_back(edge[0]);
        }

        for(auto& edge:edges2){
            adj2[edge[0]].push_back(edge[1]);
            adj2[edge[1]].push_back(edge[0]);
        }

        int best = 0;
        for(int i=0;i<n;i++) {
            int connections = bfs(i, adj2, k-1);
            best = max(best, connections);
        }

        vector<int> res(m);
        for(int i=0;i<m;i++) {
            int connections = bfs(i, adj1, k);
            res[i] = connections+best;
        }

        return res;
    }
};


// we are doing a normal bfs, in bfs we are just counting how many node we can cover 
// in k / k-1 levels
// first do bfs on edges2 and find the node through which we can cover max nodes
// then in second bfs on edges1, add the best we got from edge2 with each node from edge1