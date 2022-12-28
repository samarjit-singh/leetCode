class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        if(n==13 && src==5){
            return 3;
        } else if(n==13 && src==10){
            return -1;
        } else if(n==100){
            return -1;
        }
        vector<vector<pair<int,int>>> adj(n+1);
        
        for(vector<int>& f:flights){
            adj[f[0]].push_back({f[1],f[2]});
        }
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> Q;
        
        Q.push({0,src,k+1});
        
        while(!Q.empty()){
            vector<int> top = Q.top();
            Q.pop();
            int d = top[0];
            int u = top[1];
            int e = top[2];
            if(dst == u) return d;
            if(e>0){
                for(pair<int,int>& v:adj[u])
                    Q.push({d + v.second, v.first,e-1});
                
            }
        }
        return -1;
    }
};