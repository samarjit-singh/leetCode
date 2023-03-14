class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum = 0;
        for(int i=0;i<k;i++){
            sum += cardPoints[i];
        }
        int ans = sum;
        int left = k-1;
        for(int right=n-1;right>=n-k;right--){
            sum -= cardPoints[left];
            left--;
            sum += cardPoints[right];
            ans = max(ans,sum);
        }
        
        
        return ans;
    }
};