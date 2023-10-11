class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> start;
        vector<int> end;
        
        for(auto& x : flowers){
            start.push_back(x[0]);
            end.push_back(x[1]);
        }
        
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        
        vector<int> ans;
        
        for(int t:people){
            int started = upper_bound(start.begin(), start.end(), t) - start.begin();
            int ended = lower_bound(end.begin(), end.end(), t) - end.begin();
            ans.push_back(started-ended);
        }
        return ans;
    }
};