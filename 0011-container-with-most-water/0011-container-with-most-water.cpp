class Solution {
public:
    int maxArea(vector<int>& height) {
        int L = 0, R = height.size()-1, maxArea = INT_MIN;
        for(int i=0;i<height.size();i++){
            int area = (R-L) * min(height[L],height[R]);
            maxArea = max(area,maxArea);
            if(height[L]<height[R])
                L++;
            else 
                R--;
        }
        return maxArea;
    }
};