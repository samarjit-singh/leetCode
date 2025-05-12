class Solution {
public:

    void backtrack(vector<int>& digits, set<int>& res, int digitIndex, int digit, vector<bool>& used) {
        if(digitIndex == 3) {
            if(digit % 2 == 0) {
                res.insert(digit);
            }
            return;
        }

        for(int i=0;i<digits.size();i++) {
            if(used[i]) continue;

            if(digitIndex == 0 && digits[i] == 0) continue;

            used[i] = true;
            backtrack(digits, res, digitIndex+1, digit*10+digits[i], used);
            used[i] = false;
        }
    }

    vector<int> findEvenNumbers(vector<int>& digits) {
        sort(digits.begin(), digits.end());
        vector<bool> used(digits.size(), false);

        set<int> res;
        backtrack(digits, res, 0, 0, used);

        vector<int> result(res.begin(), res.end());

        return result;
    }
};