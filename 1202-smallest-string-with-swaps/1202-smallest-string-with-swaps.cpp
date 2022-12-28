class Solution {
public:
    
     class UnionFind{
        
        public:
            int count;
            vector<int> parent,size;
            UnionFind(int n){
                count = n;
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
                count--;
                return true;
            }
         
        
    };
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();
        
        if(pairs.size()==0){
            return s;
        }
        
        UnionFind uf(n);
        
        for(auto pair:pairs){
            uf.join(pair[0],pair[1]);
        }
        
        map<int,string> m;
        
        for(int i=0;i<n;i++){
            int parent = uf.find(i);
            uf.parent[i] = parent;
            m[parent] += s[i];
        }
        
        if(uf.count==1){
            sort(s.begin(),s.end());
            return s;
        }
        
        for(auto pairs:m){
            int i = pairs.first;
            string s = pairs.second;
            sort(s.begin(), s.end(), greater<char>());
            m[i] = s;
        }
        
        for(int i=0;i<n;i++){
            int parent = uf.find(i);
            s[i] = m[parent].back();
            m[parent].pop_back();
        }
        return s;
    }
};