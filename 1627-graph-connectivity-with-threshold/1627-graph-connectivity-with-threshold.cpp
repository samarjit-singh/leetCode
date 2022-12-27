class Solution {
public:
    
    class UnionFind{
        vector<int> parent,size;
        public:
            UnionFind(int n){
                size.resize(n);
                parent.resize(n);
                for(int i=0;i<n;i++){
                    parent[i] = i;
                    size[i] = 1;
                }
            }

            int find(int x){
                if(parent[x]!=x){
                    return find(parent[x]);
                }
                return x;
            }

            bool join(int x,int y){
                int a = find(x);
                int b = find(y);
                if(a==b) return false;
                if(size[a]>size[b]){
                    size[a] += size[b];
                    parent[b] = a;
                } else {
                    size[b] += size[a];
                    parent[a] = b;
                }
                return true;
            }
        
    };
    
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        
        UnionFind uf(n+1);
        
        for(int i=threshold+1;i<=n;i++){
            for(int j=2*i;j<=n; j+=i){
                    uf.join(i,j);
            }
        }
        
        vector<bool> ans;
        int pi,pj;
        
        for(auto& q: queries){
            pi = uf.find(q[0]);
            pj = uf.find(q[1]);
            
            ans.push_back(pi==pj);
        }
        
        return ans;
        
    }
};