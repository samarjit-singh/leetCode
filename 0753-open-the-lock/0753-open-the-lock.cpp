class Solution {
public:
    vector<string> children(string lock) {
        vector<string> result;

        for (int i = 0; i < 4; i++) {
            string temp = lock;

            temp[i] = (lock[i] - '0' + 1) % 10 + '0';
            result.push_back(temp);

            temp[i] = (lock[i] - '0' - 1 + 10) % 10 + '0';
            result.push_back(temp);
        }

        return result;
    }
    
    int openLock(vector<string>& deadends, string target) {
        set<string> s(deadends.begin(), deadends.end());

        if (s.count("0000")) return -1;

        queue<pair<string, int>> q; // lock, turn;
        q.push({"0000", 0});

        while(!q.empty()){
            auto [lock, turn] = q.front();
            q.pop();

            if(lock == target){
                return turn;
            }

            for(auto child : children(lock)){
                if(!s.count(child)){
                    q.push({child, turn + 1});
                    s.insert(child);
                }
            }
        }

        return -1;
    }
};