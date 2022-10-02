class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        
        vector<vector<int>> ans;
        
        for(int i=0;i<image.size();i++){
           reverse(image[i].begin(),image[i].end()); 
        }
        
        for(int i=0;i<image.size();i++){
            
            vector<int> anss;
            
            for(int j=0;j<image[i].size();j++){
                if(image[i][j]==1){
                    anss.push_back(0);
                } else {
                    anss.push_back(1);
                }
            }
            ans.push_back(anss);
        }
        
        return ans;
    }
};