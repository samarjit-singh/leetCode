class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;
        multiset<int> pq{0};
        vector<pair<int,int>> point;
        
        for(auto b: buildings){
            point.push_back({b[0],-b[2]}); // starting point of building
            point.push_back({b[1],b[2]}); // ending point of building
        }
        
        sort(point.begin(),point.end());
        
        int ongoingHeight = 0;
        
        for(int i=0;i<point.size();i++){
            int currentPoint = point[i].first;
            int heightAtCurrentPoint = point[i].second;
            
//             pq is the fall back 
//             if its the starting point of the building add it to the multiset
//             if its the end point of the building we remove it from the multiset
            if(heightAtCurrentPoint<0){
                pq.insert(-heightAtCurrentPoint);
            } else {
                pq.erase(pq.find(heightAtCurrentPoint));
            }
            
//             rebegin return point of the right most element
            auto pqTop = *pq.rbegin();
            
            if(ongoingHeight!=pqTop){
                ongoingHeight = pqTop;
                ans.push_back({currentPoint, ongoingHeight});
            }
            
        }
        
        return ans;
    }
};