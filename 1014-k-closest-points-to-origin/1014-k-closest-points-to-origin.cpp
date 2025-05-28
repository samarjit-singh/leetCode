class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> pq;
        vector<vector<int>> result;

        for(auto point : points) {
            int x = point[0];
            int y = point[1];
            pq.push({x*x + y*y,point});
        }

        while(k>0) {
            auto curr = pq.top();
            pq.pop();

            result.push_back(curr.second);
            k--;
        }

        return result;
    }
};