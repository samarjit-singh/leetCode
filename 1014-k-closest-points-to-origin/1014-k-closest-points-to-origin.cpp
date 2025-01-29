class Solution {
public:
    int calcDist(int x, int y){
        int x1 = abs(x-0) * abs(x-0);
        int y1 = abs(y-0) * abs(y-0);

        return x1+y1;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> res;
        for(int i=0;i<points.size();i++){
            int dist = calcDist(points[i][0], points[i][1]);
            pq.push({dist, {points[i][0], points[i][1]}});
        }

        for(int i=0;i<k;i++){
            vector<int> temp;
            temp.push_back(pq.top().second.first);
            temp.push_back(pq.top().second.second);
            res.push_back(temp);
            pq.pop();
        }

        return res;
    }
};