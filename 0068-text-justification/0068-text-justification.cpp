class Solution {
public:

    string insertSpace(vector<string>& words,int sizeOfCurr, int maxWidth){
        string line = "";

        int spaceNeeded = maxWidth - sizeOfCurr;
        int wordSize = words.size();

        if(wordSize == 1){
            line += words[0];
            line += string(spaceNeeded, ' ');
            return line;
        }

        int spacePerGap = spaceNeeded / (wordSize-1);
        int extraSpace = spaceNeeded % (wordSize-1);

        for(int i = 0; i < words.size()-1; i++){
            line += words[i];

            line += string(spacePerGap, ' ');

            if(extraSpace > 0){
                line += " ";
                extraSpace--;
            }
        }
        line += words.back();

        return line;
    }

    string lastLineSpace(vector<string>& words,int sizeOfCurr, int maxWidth){
        string line = "";

        for(int i = 0; i < words.size(); i++){
            line += words[i];
            if (i < words.size() - 1) {
                line += " ";
            }
        }
        int spaceLeft = maxWidth - line.size();

        line += string(spaceLeft, ' ');

        return line;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        vector<string> curr;
        int sizeOfCurr = 0;

        for(int i = 0; i < words.size(); i++) {
            if (sizeOfCurr + curr.size() + words[i].size()  > maxWidth) {
                string line = insertSpace(curr, sizeOfCurr, maxWidth);
                res.push_back(line);
                curr.clear();
                sizeOfCurr = 0;
            }

            curr.push_back(words[i]);
            sizeOfCurr += words[i].size();
        }

        string lastLine = lastLineSpace(curr, sizeOfCurr, maxWidth);
        res.push_back(lastLine);
        for(int j=0;j<curr.size();j++){
            cout<<curr[j]<<" ";
        }


        return res;
    }
};