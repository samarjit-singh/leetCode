#define ll long long int

class Solution {
public:
    void dfs(vector<vector<int>>& gr,vector<bool>& visited,int& count,int& i){
        visited[i] = true;
        count++;
        for(int j=0;j<gr[i].size();j++){
            if(!visited[gr[i][j]]){
                dfs(gr,visited,count,gr[i][j]);
            }
        }
    }
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        
        vector<vector<int>> gr(n); //adjacenc matrix
        
        for(int i=0;i<n;i++){
            
            ll x1 = bombs[i][0];
            ll y1 = bombs[i][1];
            ll r1 = bombs[i][2];
            
            for(int j=0;j<n;j++){
                
                if(i!=j){ // cause bomb will defuse itself
                    ll x = abs(x1-bombs[j][0]);
                    ll y = abs(y1-bombs[j][1]);
                    if(x*x+y*y<=r1*r1){
                        gr[i].push_back(j);
                    }
                }
                
            }
            
        }
        
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            int count = 0;
            vector<bool> visited(n,false);
            dfs(gr,visited,count,i);
            ans = max(ans,count);
        }
        
        return ans;
    }
};