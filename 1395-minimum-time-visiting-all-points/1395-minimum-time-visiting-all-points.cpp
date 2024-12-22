class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int res = 0;
        int x1 = points[0][0];
        int y1 = points[0][1];
        int i=1;

        while(i < points.size()){
            int x2 = points[i][0];
            int y2 = points[i][1];
            res += max(abs(x2-x1), abs(y2-y1));
            i++;
            x1 = x2; // Update x1 to the current point's x-coordinate
            y1 = y2;
        }

        return res;
    }
};