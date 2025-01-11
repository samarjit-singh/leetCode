class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int,int>> q;
        int time = 0;

        for(int i = 0; i < tickets.size(); i++){
            q.push({i, tickets[i]});
        }

        while(!q.empty()) {
            auto top = q.front();
            q.pop();


            time++;

            int operation = top.second - 1;

            if(top.first == k && operation == 0){
                break;
            }

            if(operation == 0) {
                continue;
            } else {
                q.push({top.first, operation});
            }


        }   

        return time;
    }
};