class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        
        sort(verticalCuts.begin(),verticalCuts.end());
        sort(horizontalCuts.begin(),horizontalCuts.end());
        
        int maxHeight = max(horizontalCuts[0], h-horizontalCuts[horizontalCuts.size()-1]);
        
        for(int i=1;i<horizontalCuts.size();i++){
            int horizontalWidth = horizontalCuts[i]-horizontalCuts[i-1];
            maxHeight = max(maxHeight,horizontalWidth);
        }
        
        int maxWidth = max(verticalCuts[0], w-verticalCuts[verticalCuts.size()-1]);
        
        for(int i=1;i<verticalCuts.size();i++){
            int verticalWidth = verticalCuts[i]-verticalCuts[i-1];
            maxWidth = max(maxWidth,verticalWidth);
        }
        long ans = 1L * maxHeight*maxWidth;
        
        return (int) (ans%1000000007);
    }
};