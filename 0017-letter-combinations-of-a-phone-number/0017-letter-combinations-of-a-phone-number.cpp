class Solution {
public:
    
    void printkeypad(int num,string output,string options[],vector<string>& ans){
        if(num==0){
            ans.push_back(output);
            return;
        }
        
        int n1 = num%10;
        string s1 = options[n1];
        for(int i=0;i<s1.length();i++){
            printkeypad(num/10, s1[i]+output, options,ans);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> ans1;
        if(digits=="")
            return ans1;
        int num = stoi(digits);
        vector<string> ans;
        string output = "";
        string options[] = {"", "", "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        printkeypad(num,output,options,ans);
        
        return ans;
    }
};