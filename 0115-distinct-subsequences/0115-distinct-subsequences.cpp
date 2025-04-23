class Solution {
public:

    int dfs(string& s, string& t, int index, int currStr, vector<vector<int>>& dp) {
        if(currStr == t.size()) {
            return 1;
        }

        if(index >= s.size() || currStr > t.size()) {
            return 0; 
        }

        if(dp[index][currStr] != -1) {
            return dp[index][currStr];
        }

        int ways = 0;

        if(s[index] == t[currStr]){
            // pick
            ways += dfs(s, t, index+1, currStr + 1, dp);
        }


        // not pick
        ways += dfs(s, t, index+1, currStr, dp);


        return dp[index][currStr] = ways;
    }

    int numDistinct(string s, string t) {
        int count = 0;
        string currStr = "";

        int n = s.size();
        int m = t.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return dfs(s,t, 0, 0, dp);
    }
};


// pick r
// notpick a
// currStr = "r".  

// pick a 
// notpick a
// currStr = "ra"

// pick a
// not pick
// currStr = "a"



// pick r
// notpick a
// currStr = "r".  

// pick a 
// notpick a
// currStr = "ra"

// pick a
// not pick
// currStr = "a"