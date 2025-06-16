class Solution {
public:
    int maxDiff(int num) {
        string original = to_string(num);

        string max_str = original;
        for(char c:original) {
            if(c != '9') {
                char target = c;
                for(char& ch:max_str) {
                    if(ch == target) ch = '9';
                }
                break;
            }
        }

        string min_str = original;
        char target = 0;
        if(original[0] != '1') {
            target = original[0];
            for(char& ch:min_str) {
                if(ch == target) ch = '1';
            }
        } else {
            for(int i=1;i<original.size();i++) {
                if(original[i]!='0' && original[i]!='1') {
                    target = original[i];
                    break;
                }
            }
            if(target) {
                for(char& ch:min_str) {
                    if(ch == target) ch='0';
                }
            }
        }

        int maxVal = stoi(max_str);
        int minVal = stoi(min_str);

        return maxVal - minVal;
    }
};

// For min_str
// If the first digit is not 1, replace it with 1 (to keep it valid and minimal).
// Else, replace the next digit (not 0 or 1) with 0 (for maximum minimization without leading zero).