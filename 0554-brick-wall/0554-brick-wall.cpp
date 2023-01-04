class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int,int> umap;
        int untouchedBrick = 0;
        for(int i=0;i<wall.size();i++){
            int brickEnd = 0;
            for(int j=0;j<wall[i].size()-1;j++){ // wont be considering the last brick
                brickEnd += wall[i][j];
                umap[brickEnd]++;
                untouchedBrick = max(umap[brickEnd],untouchedBrick);
            }
        }
        
        return wall.size()-untouchedBrick;
    }
};