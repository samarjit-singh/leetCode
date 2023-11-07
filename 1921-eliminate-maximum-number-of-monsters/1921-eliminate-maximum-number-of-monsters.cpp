class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<int> time;
        
        for(int i=0;i<dist.size();i++){
            if(dist[i] % speed[i] == 0){
                time.push_back(dist[i]/speed[i]);
            } else {
                time.push_back((dist[i]/speed[i])+1);
            }
        }
        
        sort(time.begin(),time.end());
        
        int monster = 0;
        
        for(int i=0;i<time.size();i++){
            if(time[i]-monster <= 0){
                return i; // able to kill only these many mosters
            } else {
                monster++;
            }
        }
        return monster;
    }
};