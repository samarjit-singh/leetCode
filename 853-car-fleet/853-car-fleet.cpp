class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<float> fleet;
        
        vector<pair<int,float>> ptime;
        
        for(int i=0;i<position.size();i++){
            ptime.push_back({position[i], float(target - position[i]) / speed[i]});
        }
        
        sort(ptime.begin(),ptime.end());
        
        for(int i=0; i < position.size(); i++){
            float fleet_i = ptime[i].second;
            
            while(fleet.size() && fleet_i>=fleet.top()){
                fleet.pop();
            }
            fleet.push(fleet_i);
        }
        return fleet.size();
    }
};