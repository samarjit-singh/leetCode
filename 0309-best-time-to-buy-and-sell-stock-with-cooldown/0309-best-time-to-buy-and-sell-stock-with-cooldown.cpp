class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<1) return 0;
        int A = 0, C = 0, B = -prices[0]; // a is for BUY c is for sold and b id for hold
        for(int i = 1;i<prices.size();i++){
            int temp = A;
            A = max(A,C);
            C = B+prices[i];
            B = max(B,temp-prices[i]);
        }
        return max(A,C);
    }
};