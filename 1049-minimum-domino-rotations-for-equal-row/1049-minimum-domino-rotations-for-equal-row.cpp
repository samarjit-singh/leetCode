class Solution {
public:
    
    int util(int number, vector<int>& tops, vector<int>& bottoms) {
        int count = 0;

        for(int i=0;i<tops.size();i++) {
            if(tops[i] == number) continue;
            else if(bottoms[i] == number) count++;
            else return INT_MAX; // if the number does not exist in top or bottom that number cannot be made equal in any row
        }
        return count;
    }

    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int minRotation = INT_MAX;

        for(int number = 1; number <= 6; number++) { 
            int countTops = util(number, tops, bottoms);
            
            int countBottom = INT_MAX;

            if(countTops != INT_MAX) { // if tops cannot be made equal then bottom also cannot be made equal
                countBottom = util(number, bottoms, tops);
            }

            minRotation = min(minRotation, min(countTops, countBottom));
        }

        return minRotation == INT_MAX ? -1 : minRotation;
    }
};


// in this total unique numbers is 1 - 6, for each number I'll check
// if I can make tops or bottoms same, note if tops cannot be made equal
// then bottom also cannot be made equal