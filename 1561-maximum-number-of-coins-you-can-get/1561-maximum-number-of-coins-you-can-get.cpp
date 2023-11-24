class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        sort(piles.begin(),piles.end());
        int i = 0;
        int j = n-2;
        int k = n-1;
        int total = 0;
        
        
        while(i<j){
            total += piles[j];
            i++;
            j -= 2;
            k -= 2;
        }
        return total;
    }
};