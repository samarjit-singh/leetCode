class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int MOD = 1000000007;
        sort(arr.begin(),arr.end());
        
        unordered_map<int, long long> dp;
        
        for(int i=0;i<arr.size();i++){
            dp[arr[i]] = 1;
            for(int j=0;j<i;j++){
                if(arr[i] % arr[j] == 0){
                    int factor = arr[i]/arr[j];
                    if(dp.count(factor)){
                        dp[arr[i]] = (dp[arr[i]] + dp[arr[j]] * dp[factor]) % MOD;       
                    }
                    // cout<<"factor "<<factor<<" dp factor "<< dp[factor]<<endl;
                }
            }
        }
        
        long long result = 0;
        
        for(auto x:dp){
            // cout<<x.first<<" "<<x.second<<endl;
            result = (result + x.second)%MOD;
        }
        
        return result;
         
    }
};