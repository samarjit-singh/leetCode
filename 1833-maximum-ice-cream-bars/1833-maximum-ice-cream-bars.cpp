class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        
        int n = costs.size();
        
        for(int i=0;i<costs.size();i++){
            if(coins>=costs[i]){
                coins -= costs[i];
            } else {
                return i;
            }
        }
        
        return n;
    }
};