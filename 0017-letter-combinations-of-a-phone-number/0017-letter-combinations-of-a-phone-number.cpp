class Solution {
public:
    vector<string> letters = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void backtrack(string subStr, vector<string>& result, vector<string>& letterComb, int index) {
        if(index == letterComb.size()) {
            result.push_back(subStr);
            return;
        }

        for(char c:letterComb[index]){
            backtrack(subStr+c, result, letterComb, index + 1);
        }

    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {}; 

        vector<string> letterComb;
        vector<string> result;

        for(int i=0;i<digits.size();i++){
            int num = digits[i] - '0';
            if (num >= 2 && num <= 9) { 
                letterComb.push_back(letters[num - 1]);
            }
        }

        backtrack("", result, letterComb, 0);

        return result;
    }
};