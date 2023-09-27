class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long decodedLength = 0;  // Using long long for large numbers.
        int n = s.size();

        // Calculate the total length of the decoded string.
        for (char c : s) {
            if (isdigit(c)) {
                int repeat = c - '0';
                decodedLength *= repeat;
            } else {
                decodedLength++;
            }
        }

        // Traverse the string backwards to find the kth character.
        for (int i = n - 1; i >= 0; i--) {
            char c = s[i];
            if (isdigit(c)) {
                int repeat = c - '0';
                decodedLength /= repeat;
                k %= decodedLength;
            } else {
                if (k == 0 || k == decodedLength) {
                    return string(1, c);
                }
                decodedLength--;
            }
        }

        return "";  // This should not happen if the input is valid.
    }
};
