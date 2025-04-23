class Solution {
public:

    int dfs(string s, string t, int index, string currStr) {
        cout<<currStr<<endl;

        if(currStr == t) {
            return 1;
        }

        if(index >= s.size() || currStr.size() > t.size()) {
            return 0; 
        }

        // not pick
        int notpick = dfs(s, t, index+1, currStr);

        // pick
        int pick = dfs(s, t, index+1, currStr += s[index]);

        return pick + notpick;
    }

    int numDistinct(string s, string t) {
        int count = 0;
        string currStr = "";
        return dfs(s,t, 0, currStr);
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