class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>,int> umap;
        
        for(int i=0;i<grid.size();i++){
            umap[grid[i]]++;
        }
        
        int count = 0;

        for(int j=0;j<grid[0].size();j++){
            vector<int> temp;
            for(int i=0;i<grid.size();i++){
                temp.push_back(grid[i][j]);
            }
            
            if(umap[temp]){
                count += umap[temp];
            }
        }
        
        for (auto x : umap){
            cout<<x.second<<" ";
        }
        
        return count;
    }
};