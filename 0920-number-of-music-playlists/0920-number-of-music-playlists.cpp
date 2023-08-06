class Solution {
public:
    
    long long MOD = 10^9+7;
    
    long long solve(int n,int g,int k,vector<vector<long long>>&memo){
        
        if(g==0 && n ==0){
            return 1;
        } 
        
        if(g==0 || n ==0){
            return 0;
        }
        
        if(memo[n][g] != -1){
            return memo[n][g];
        }
        
        long long replayOld = solve(n,g-1,k,memo) * (max(0,n-k));
        long long playNew = solve(n-1,g-1,k,memo) * n;
        
        return memo[n][g] = (replayOld+playNew) % 1000000007;
        
    }
    
    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<long long>> memo(n+1,vector<long long>(goal+1,-1));
        
        return solve(n,goal,k,memo);
    }
};