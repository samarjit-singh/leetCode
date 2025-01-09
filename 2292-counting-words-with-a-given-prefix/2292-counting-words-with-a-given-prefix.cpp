class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int sizeOfPref = pref.size();
        int count = 0;

        for(int i=0;i<words.size();i++){
            if(words[i].substr(0, sizeOfPref) == pref){
                count++;
            }
        }

        return count;
    }
};