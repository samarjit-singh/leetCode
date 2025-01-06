class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {

        vector<vector<int>> subordinates(n);
        for(int i=0;i<n;i++){
            if(manager[i] != -1){
                subordinates[manager[i]].push_back(i);
            }
        }

        queue<pair<int,int>> q;
        q.push({headID,0});
        int time = 0;

        while(!q.empty()){
            auto [top, currentTime] = q.front();
            q.pop();
            
            time = max(time, currentTime);

            for (int subordinate : subordinates[top]) {
                q.push({subordinate, currentTime + informTime[top]});
            }
        }

        return time;
    }
};