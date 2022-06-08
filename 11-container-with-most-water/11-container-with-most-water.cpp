class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int L = 0, R = n-1,maxArea = INT_MIN;
        
        while( L < R ){
            int area = (R-L) * min(height[R],height[L]);
            maxArea = max(maxArea,area);
            if(height[L]<height[R]){
                L++;
            } else {
                R--;
            }
        }
        return maxArea;
    }
};