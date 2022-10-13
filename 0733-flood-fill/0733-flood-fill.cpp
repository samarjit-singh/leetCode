class Solution {
public:
    
    bool isValid(vector<vector<int>>& image,int i,int j,int n,int m,int oldColor){
        if(i>=0 && i<n && j>=0 && j<m && image[i][j] == oldColor){
            return true;
        }
        return false;
    }
    
    void floodFillRec(vector<vector<int>>& image,int i,int j,int n,int m,int oldColor,int color){
        image[i][j] = color;
        
        if(isValid(image,i+1,j,n,m,oldColor)){
            floodFillRec(image,i+1,j,n,m,oldColor,color);
        }
        
        if(isValid(image,i-1,j,n,m,oldColor)){
            floodFillRec(image,i-1,j,n,m,oldColor,color);
        }
        
        if(isValid(image,i,j+1,n,m,oldColor)){
            floodFillRec(image,i,j+1,n,m,oldColor,color);
        }
        
        if(isValid(image,i,j-1,n,m,oldColor)){
            floodFillRec(image,i,j-1,n,m,oldColor,color);
        }
    }
    
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int n = image.size();
        int m = image[0].size();
        
        int oldColor = image[sr][sc];
        
        if(oldColor==color)
            return image;
                
        floodFillRec(image,sr,sc,n,m,oldColor,color);
                
         
        
        return image;
        
        
    }
};