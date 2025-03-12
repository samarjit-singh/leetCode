class Solution {
public:
    bool dfs(vector<int>& matchsticks, vector<int>& sides, int index, int lengthOfSide) {
        if (index == matchsticks.size()) {
            return sides[0] == lengthOfSide && sides[1] == lengthOfSide &&
                   sides[2] == lengthOfSide && sides[3] == lengthOfSide;
        }

        for (int i = 0; i < 4; i++) {
            if (sides[i] + matchsticks[index] > lengthOfSide) continue;  
            
            sides[i] += matchsticks[index]; 
            if (dfs(matchsticks, sides, index + 1, lengthOfSide)) return true;
            sides[i] -= matchsticks[index];  
        }

        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        int sumOfMatchsticks = accumulate(matchsticks.begin(), matchsticks.end(), 0);

        int lengthOfSide = sumOfMatchsticks / 4;
        vector<int> sides(4, 0);

        sort(matchsticks.rbegin(), matchsticks.rend());  

        return dfs(matchsticks, sides, 0, lengthOfSide);
    }
};
