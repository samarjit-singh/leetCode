class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> umap;

        for(int i=0;i<order.size();i++){
            umap[order[i]] = i;
        }

        for(int i=0;i<words.size()-1;i++){
            string word1 = words[i];
            string word2 = words[i+1];

            for(int j=0;j<word1.size();j++){
                if(j == word2.size()){ // means word2 is prefix of word1
                    return false;
                }

                if(word1[j] != word2[j]){ // first different character
                    if(umap[word2[j]] < umap[word1[j]]){
                        return false;
                    }
                    break;
                }
            }
        }

        return true;
    }
};