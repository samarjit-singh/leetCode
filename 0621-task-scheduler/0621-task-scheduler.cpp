class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> umap;

        for(auto x:tasks){
            umap[x]++;
        }

        priority_queue<pair<int, char>> pq;

        for(auto x:umap){
            pq.push({x.second, x.first});
        }

        int time = 0;
        queue<pair<int, pair<int, char>>> q;

        while(!pq.empty() || !q.empty()){
            time++;

            if(!pq.empty()){
                auto pqTop = pq.top();
                pq.pop();
                if(pqTop.first - 1 > 0){
                    q.push({time + n, {pqTop.first - 1, pqTop.second}});
                }
            }

            if (!q.empty() && q.front().first == time) {
                auto qTop = q.front();
                q.pop();
                pq.push({qTop.second.first, qTop.second.second});
            }
        }

        return time;
    }
};