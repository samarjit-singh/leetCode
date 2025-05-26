class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> umap;
        int counter = 0;
        bool hasMiddle = false;

        for (string& word : words) {
            string rev = word;
            reverse(rev.begin(), rev.end());

            if (umap[rev] > 0) {
                counter += 4;
                umap[rev]--;
            } else {
                umap[word]++;
            }
        }

        for (auto& [word, freq] : umap) {
            if (word[0] == word[1] && freq > 0) {
                hasMiddle = true;
                break;
            }
        }

        if (hasMiddle) counter += 2;

        return counter;
    }
};
