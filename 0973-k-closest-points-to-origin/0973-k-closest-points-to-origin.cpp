class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>> pq;
        vector<vector<int>> ans(k);
        
        for(auto& p:points){
            int x = p[0], y = p[1];
            pq.push({x*x+y*y, x,y});
            if(pq.size()>k){
                pq.pop();
            }
        }
        
        for(int i=0;i<k;++i){
            vector<int> temp = pq.top();
            pq.pop();
            ans[i] = {temp[1],temp[2]};
        }
        return ans;
    }
};