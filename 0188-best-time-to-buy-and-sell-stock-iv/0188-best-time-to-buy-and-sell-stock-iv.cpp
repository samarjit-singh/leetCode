class Solution {
public:
    
	// 3-DP array because there where three changing parameters.
	// 1) size of array, 
	// 2)whether we buy or sell (0/1) 
	// 3) k
	
    int dp[1001][2][101];
	
    int dp_fun(int k,vector<int>& prices,int idx,int b){
	// if k==0 we simply return 0 as all the k transactions are done 
        if(k==0){
            return 0;
        }
        
		// if we reached the end of the array then we return 0;
		
        if(idx==prices.size()){
            return 0;
        }
        
		//  Returning the already solved problem(overlapping subproblem)
		
        if(dp[idx][b][k] != -1){
            return dp[idx][b][k];
        }
        
		// if buying is possible and when selling is possible
        if(b==1){
            return dp[idx][b][k] = max((-prices[idx]+dp_fun(k,prices,idx+1,0)), dp_fun(k,prices,idx+1,1));
        }
        else{
            return dp[idx][b][k] = max((prices[idx]+dp_fun(k-1,prices,idx+1,1)), dp_fun(k,prices,idx+1,0));
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        
        memset(dp,-1,sizeof(dp));
        return dp_fun(k,prices,0,1);
    }
};