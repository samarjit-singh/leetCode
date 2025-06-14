class Solution {
public:
    int minMaxDifference(int num) {
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
        for(char c:original) {
            if(c != '0') {
                char target = c;
                for(char& ch:min_str) {
                    if(ch == target) ch = '0';
                }
                break;
            }
        }

        int maxVal = stoi(max_str);
        int minVal = stoi(min_str);

        return maxVal - minVal;
    }
};

// For max value = choose the first non 9 digit and replace all its occurrences with 9
// For min value = choose the first non 0 digit and replace all its occurrences with 0