class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int,int>>q;
        for(int i=0;i<tickets.size();i++){
            q.push({tickets[i],i});
        }
        
        int ans = 0;
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            p.first--;
            ans++;
            if(p.second == k && p.first == 0)
                return ans;
            else if(p.first!=0)
                q.push(p);
        }
        return ans;
    }
};