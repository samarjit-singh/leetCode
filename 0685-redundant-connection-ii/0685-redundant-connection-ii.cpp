class Solution {
public:
    
    int find(int x, vector<int> &par){
        if(par[x]!=x){
            return find(par[x],par);
        }
        return x;
    }
    
    bool MakeUnion(int x,int y,vector<int> &rank,vector<int> &parent){
        
        int lx = find(x,parent);
        int ly = find(y,parent);
        
        if(lx != ly){
            
            if(rank[lx]>rank[ly]){
                parent[ly] = lx;
            } else if(rank[lx]<rank[ly]){
                parent[lx] = ly;
            } else {
                parent[lx] = ly;
                rank[ly]++;
            }
            return false;
        } else {
            return true;
        }
        
    }
    
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();
        vector<int> parent(n+1);
        vector<int> rank(n+1,0);
        
        for(int i=0;i<n;i++){
            parent[i] = i;
            rank[i] = 1;
        }
        
        vector<int> indegree(n+1 , -1);
        
        int black_list1=-1;
         int black_list2=-1;
        
        for(int i=0;i<n;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            if(indegree[v]==-1){
                indegree[v] = i;
            } else {
                black_list1 = i;
                black_list2 = indegree[v];
                break;
            }
        }
        
        
        
        for(int i=0;i<n;i++){
            if(i == black_list1){
                continue;
            }
            
            int u = edges[i][0];
            int v = edges[i][1];
            
            bool flag = MakeUnion(u,v,rank,parent);
            
            if(flag == true){
                if(black_list1 == -1){
                    return edges[i]; // case 2
                } else {
                    return edges[black_list2]; // case 3
                }
            }
            
        }
        
        return edges[black_list1];
        
    }
};