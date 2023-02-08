class Solution {
public:
    
    int util(vector<int>& prices,int i,int k,bool buy,vector<vector<int>>& v){
        if(i >= prices.size() || k<=0) return 0;
        
        if(v[i][buy]!=-1) return v[i][buy];
        
        if(buy) {
            //-prices[i], because bought stock of prices[i], expend money
            return v[i][buy] = max(-prices[i]+util(prices,i+1,k,!buy,v),util(prices,i+1,k,buy,v));
        } else { //it's time to sell , now decrease k, we have done 1 transaction
            //+prices[i], because we now gain (i.e) sell our stock at rate of prices[i]
            return v[i][buy] = max(prices[i]+util(prices,i+1,k-1,!buy,v), util(prices,i+1,k,buy,v));
        }
        
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> v(n,vector<int>(2,-1));
//         we are passing prices vector,index, transactions , buy/sell , vector
        return util(prices,0,1,1,v);
    }
};