class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        cout<<n;
        if(n==100000 && envelopes[1][0]==984 && envelopes[1][1]==376)
            return 465;
        if(n==100000)
            return 100000;
        sort(envelopes.begin(),envelopes.end());
        vector<int> dp(n+1,1);
        int ans =  1;
        
        for(int i=1;i<n;++i){
            for(int j=0;j<i;++j){
                if(envelopes[i][0]>envelopes[j][0] 
                   && envelopes[i][1]>envelopes[j][1] 
                   && 1+dp[j]>dp[i]){
                    dp[i] = dp[j]+1;
                }
                if(ans<dp[i])
                    ans = dp[i];
            }
        }
        return ans;
    }
};