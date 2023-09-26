class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> charCount;
        unordered_map<char, bool> used;
        string result = "";

        // Count the frequency of each character in the input string
        for (char c : s) {
            charCount[c]++;
        }

        for (char c : s) {
            charCount[c]--; // Decrease the count of the current character

            if (used[c]) {
                continue; // Skip characters already used
            }

            // Remove characters from the result string while they are larger
            // and there are more occurrences later in the string
            while (!result.empty() && c < result.back() && charCount[result.back()] > 0) {
                used[result.back()] = false;
                result.pop_back();
            }

            // Append the current character to the result string
            result += c;
            used[c] = true;
        }

        return result;
    }
};