class Solution {
public:


    void backtrack(vector<string> &res, string &s,int i){

        if(i == s.size()){
            res.push_back(s);
            return;
        }
        
        if( isalpha(s[i]) ) {

            s[i] = toupper(s[i]);
            backtrack(res,s,i+1);

            s[i] = tolower(s[i]);
            backtrack(res,s,i+1);


        } else {
            backtrack(res,s,i+1);
        }

    }

    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        backtrack(res, s, 0);

        return res;
    }
};