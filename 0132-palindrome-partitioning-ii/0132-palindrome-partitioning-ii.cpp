class Solution {
public:
    
    bool isPalindrom(int i,int j, string &s){
        if(i>=j)return true;
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    
    int util(int i,int n,string &s,vector<int>& dp){
        if(i >= n or isPalindrom(i, n, s)) return 0;
        
        int minCost = INT_MAX;
        
        if(dp[i]!=-1) return dp[i];
        
        for(int j=i;j<n;j++){
            if(isPalindrom(i,j,s)){
                int cost = 1 + util(j+1,n,s,dp);
                minCost = min(cost,minCost);
            }
            
        }
        
        return dp[i] = minCost;
    }
    
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n+1,-1);
        return util(0,n,s,dp)-1; // -1 because it does partitioning at the end
    }
};
// basically it does partion for every sing element in the string and the gradually
// start minimizing the partitioning for every palindrome