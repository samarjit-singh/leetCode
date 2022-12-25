class Solution {
public:
    
    bool checkSameGroup(vector<int>& stone1 , vector<int>& stone2){
        if(stone1[0] == stone2[0] || stone1[1] == stone2[1]) return true;
        
        return false;
    }
    
    void dfs(vector<int>& visited,vector<vector<int>>& stones,int index){
        visited[index] = 1;
        
        for(int i=0;i<stones.size();i++){
            if(visited[i]!=1 && checkSameGroup(stones[index],stones[i])){
                dfs(visited,stones,i);
            }
        }
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> visited(n,0);
        int components = 0;
        
        for(int i=0;i<n;i++){
            if(visited[i]!=1){
                components++;
                dfs(visited,stones,i);
            }
        }
        return n-components;
    }
};