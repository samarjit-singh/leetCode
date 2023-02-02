class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n<2) return 0;
        
        int p1 = prices[0], p2 = prices[n-1];
        
        vector<int> profit1(n, 0);
        vector<int> profit2(n, 0);
        
        for(int i=1;i<n;i++){
//             the below two line of code won't be updated everytime
            profit1[i] = max(profit1[i-1], prices[i]-p1);
            p1 = min(p1,prices[i]);
            
            int j = n-1-i; // this j will start from index n-2
            profit2[j] = max(profit2[j+1], p2 - prices[j]);
            p2 = max(p2,prices[j]);
        }
        
        int profit = 0;
        for(int i=0;i<n;i++){
            profit = max(profit,profit1[i] + profit2[i]);
        }
        return profit;
    }
};