class Solution {
public:
    
    struct dsu{
      vector<int> par,cou;
        
        dsu(int n){
            par = vector<int>(n);
            cou = vector<int>(n,1);
            for(int i=0;i<n;i++){
                par[i] = i;
            }
        }
        
        int find(int x){
            if(par[x]!=x){
                return find(par[x]);
            }
            return x;
        }
        
        bool join(int x,int y){
            int a = find(x);
            int b = find(y);
            if(a==b) return false;
            if(cou[a]<cou[b])
                swap(a,b);
            par[b] = a;
            cou[a]+=cou[b];
            return true;
        }
        
        int count(int x){
            return cou[find(x)];
        }
        
    };
    
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
//         vectors  for storing the edges
        vector<pair<int,int>> alice;
        vector<pair<int,int>> bob;
        vector<pair<int,int>> both;
        
        for(int i=0;i<edges.size();i++){
            if(edges[i][0]==1)
                alice.push_back({edges[i][1]-1,edges[i][2]-1}); // -1 cause we are doing zeo indexing
            if(edges[i][0]==2)
                bob.push_back({edges[i][1]-1,edges[i][2]-1});
            if(edges[i][0]==3)
                both.push_back({edges[i][1]-1,edges[i][2]-1});
        }
        
        dsu a(n),b(n);
        int ans = 0;
        for(auto p:both){ // making two graph with common edges
            ans+=a.join(p.first,p.second);
            b.join(p.first,p.second);
        }
        
        for(auto p:alice){ // join any left edges from alice
            ans += a.join(p.first,p.second);
        }
        
        for(auto p:bob){ // join any left edge from bob
            ans += b.join(p.first,p.second);
        }
        
        if(a.count(a.find(0))<n || b.count(b.find(0))<n) // if less than n means all edges are not connected
            return -1;
        
        return (int)edges.size()-ans;
    }
};