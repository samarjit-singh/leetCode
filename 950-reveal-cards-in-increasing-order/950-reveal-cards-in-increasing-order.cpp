class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        queue<int> que;
        
        int n = deck.size();
        
        vector<int> ans(n,0);
        
        for(int i=0;i<n;i++){
            que.push(i);
        }
        
        sort(deck.begin(),deck.end());
        
        int i = 0;
        while(!que.empty()){
            ans[que.front()] = deck[i];
            que.pop();
            que.push(que.front());
            que.pop();
            i++;
        }
        return ans;
    }
};